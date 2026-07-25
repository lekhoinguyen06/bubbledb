---
name: Bun
description: Use when building JavaScript/TypeScript applications, managing dependencies, running tests, bundling code, or creating HTTP servers. Bun is a complete toolkit replacing Node.js, npm, Jest, and esbuild with a single fast binary.
metadata:
    mintlify-proj: bun
    version: "1.0"
---

# Bun Skill

## Product Summary

Bun is an all-in-one JavaScript/TypeScript toolkit that replaces Node.js, npm, Jest, and esbuild. It ships as a single executable (`bun`) and includes:

- **Runtime**: Execute `.js`, `.ts`, `.jsx`, `.tsx` files with 4x faster startup than Node.js
- **Package Manager**: Install dependencies 25x faster than npm with `bun install`
- **Test Runner**: Jest-compatible testing with TypeScript, snapshots, and watch mode
- **Bundler**: Native bundling for browsers and servers with code splitting and plugins

**Key files and commands:**
- Configuration: `bunfig.toml` (optional, Bun-specific settings)
- Package config: `package.json` (standard Node.js format)
- Lockfile: `bun.lock` (text-based, replaces package-lock.json)
- CLI: `bun run`, `bun install`, `bun test`, `bun build`

**Primary docs:** https://bun.com/docs

---

## When to Use

Reach for Bun when:

- **Running code**: Execute TypeScript/JSX directly without compilation setup (`bun index.ts`)
- **Managing dependencies**: Install packages faster with `bun install` or `bun add`
- **Testing**: Write Jest-compatible tests with `bun test` (no Jest config needed)
- **Building**: Bundle applications for browsers or servers with `bun build`
- **Server development**: Create HTTP servers with `Bun.serve()` with built-in routing
- **Shell scripting**: Run cross-platform shell commands from JavaScript with `$` template literals
- **File operations**: Read/write files with optimized `Bun.file()` and `Bun.write()` APIs
- **Monorepos**: Manage workspaces with `bun install --filter`
- **Replacing Node.js**: Drop-in replacement for Node.js projects with better performance

---

## Quick Reference

### Essential Commands

| Task | Command |
|------|---------|
| Run a file | `bun index.ts` or `bun run index.ts` |
| Run a script | `bun run dev` (from `package.json` scripts) |
| Install dependencies | `bun install` |
| Add a package | `bun add react` or `bun add -d @types/react` |
| Remove a package | `bun remove react` |
| Run tests | `bun test` |
| Watch tests | `bun test --watch` |
| Build for browser | `bun build ./index.tsx --outdir ./dist` |
| Build for server | `bun build ./index.ts --target bun --outdir ./dist` |
| Start HTTP server | `bun index.ts` (if file exports `Bun.serve()`) |

### Configuration Files

| File | Purpose |
|------|---------|
| `bunfig.toml` | Bun-specific settings (runtime, test, bundler, package manager) |
| `package.json` | Project metadata, scripts, dependencies (standard Node.js format) |
| `tsconfig.json` | TypeScript compiler options (Bun respects this) |
| `bun.lock` | Lockfile (commit to version control) |

### Common bunfig.toml Sections

```toml
# Runtime settings
preload = ["./setup.ts"]
jsx = "react"
logLevel = "debug"

# Test runner
[test]
root = "./__tests__"
coverage = true
coverageThreshold = 0.9

# Package manager
[install]
optional = true
dev = true
linker = "isolated"  # or "hoisted"

# Server defaults
[serve]
port = 3000
```

### Package Manager Flags

| Flag | Purpose |
|------|---------|
| `-d`, `--dev` | Add as dev dependency |
| `--optional` | Add as optional dependency |
| `--peer` | Add as peer dependency |
| `-E`, `--exact` | Pin exact version (no `^` or `~`) |
| `-g`, `--global` | Install globally |
| `--production` | Skip dev dependencies on install |
| `--frozen-lockfile` | Fail if lockfile doesn't match package.json |
| `--linker hoisted` | Traditional npm-style node_modules |
| `--linker isolated` | pnpm-style isolated dependencies |

---

## Decision Guidance

### When to Use Hoisted vs. Isolated Installs

| Scenario | Use |
|----------|-----|
| New monorepo/workspace | `isolated` (prevents phantom dependencies) |
| New single-package project | `hoisted` (traditional npm behavior) |
| Existing project (pre-v1.3.2) | `hoisted` (backward compatibility) |
| Strict dependency isolation needed | `isolated` |
| Maximum compatibility with Node.js | `hoisted` |

### When to Use `bun run` vs. Direct Execution

| Scenario | Use |
|----------|-----|
| Running a package.json script | `bun run dev` |
| Running a file directly | `bun index.ts` |
| Running with lifecycle hooks (pre/post) | `bun run <script>` |
| Passing flags to bun | `bun --watch run index.ts` |

### When to Bundle vs. Run Directly

| Scenario | Use |
|----------|-----|
| Development server | Run directly: `bun index.ts` |
| Production deployment | Bundle: `bun build ./index.ts --outdir ./dist` |
| Browser/client code | Bundle with `--target browser` |
| Server code | Bundle with `--target bun` or run directly |
| Full-stack app | Bundle with `--target bun` (includes HTML imports) |

### Test Runner: Concurrent vs. Sequential

| Scenario | Use |
|----------|-----|
| Independent unit tests | `bun test --concurrent` |
| Tests with shared state | `bun test` (sequential) or `test.serial()` |
| Integration tests | `test.concurrent()` for parallel, `test.serial()` for order-dependent |
| Flaky test detection | `bun test --rerun-each 10` |

---

## Workflow

### 1. Initialize a Project

```bash
bun init my-app
# Choose template: Blank, React, or Library
cd my-app
```

This creates `package.json`, `tsconfig.json`, `bunfig.toml`, and a starter file.

### 2. Install Dependencies

```bash
bun install
# or add specific packages
bun add react
bun add -d @types/react
```

Bun creates `bun.lock` (commit this to version control).

### 3. Write Code

Create `.ts`, `.tsx`, `.js`, or `.jsx` files. Bun transpiles TypeScript and JSX automatically.

```ts
// index.ts - TypeScript works without setup
const greeting: string = "Hello, Bun!";
console.log(greeting);
```

### 4. Run Code

```bash
bun index.ts
# or via package.json script
bun run dev
```

### 5. Write Tests

Create test files matching patterns: `*.test.ts`, `*.spec.ts`, `*_test.ts`, `*_spec.ts`

```ts
// math.test.ts
import { expect, test } from "bun:test";

test("2 + 2 = 4", () => {
  expect(2 + 2).toBe(4);
});
```

Run tests:

```bash
bun test
bun test --watch
bun test --coverage
```

### 6. Build for Production

```bash
# Browser bundle
bun build ./index.tsx --outdir ./dist --target browser

# Server bundle
bun build ./index.ts --outdir ./dist --target bun

# With minification and sourcemaps
bun build ./index.tsx --outdir ./dist --minify --sourcemap linked
```

### 7. Deploy

Commit `bun.lock` to version control. In CI/CD:

```bash
bun ci  # equivalent to bun install --frozen-lockfile
bun run build
bun run test
```

---

## Common Gotchas

- **TypeScript errors on `Bun` global**: Install `@types/bun` as a dev dependency and add `"lib": ["ESNext"]` to `tsconfig.json` compilerOptions.

- **Lifecycle scripts don't run by default**: Add trusted packages to `trustedDependencies` in `package.json` to allow `postinstall` scripts.

- **`bun run` flags go before `run`**: Use `bun --watch run dev`, not `bun run dev --watch`. Flags after `run` are passed to the script itself.

- **Phantom dependencies with hoisted installs**: Use `--linker isolated` to prevent importing packages not in `package.json`.

- **Auto-install disabled in production**: Set `[install] auto = "disable"` in `bunfig.toml` or use `--frozen-lockfile` in CI.

- **Test files must match patterns**: Bun only discovers `*.test.ts`, `*.spec.ts`, `*_test.ts`, `*_spec.ts`. Nested test files work, but custom patterns require `--filter`.

- **Bundler doesn't replace tsc**: Use `bun build` for bundling, not type checking. Run `tsc --noEmit` separately for type checking.

- **WebSocket requires `server.upgrade()`**: HTTP routes don't automatically upgrade to WebSocket; call `server.upgrade(req)` in the fetch handler.

- **Idle timeout on streaming responses**: Long-lived streams (Server-Sent Events) close after 10 seconds by default. Use `server.timeout(req, 0)` to disable.

- **Environment variables not auto-injected**: Use `--env inline` or `--env PUBLIC_*` during bundling to inject `process.env` values into the bundle.

---

## Verification Checklist

Before submitting work with Bun:

- [ ] Run `bun install` to verify dependencies resolve without errors
- [ ] Run `bun test` and confirm all tests pass (or `bun test --coverage` for coverage)
- [ ] Run `bun run build` (or equivalent) and verify output files are generated
- [ ] Test the application locally: `bun index.ts` or `bun run dev`
- [ ] Verify `bun.lock` is committed to version control
- [ ] Check `bunfig.toml` for any environment-specific settings that should be in `.env` instead
- [ ] Confirm TypeScript has no errors: `bun run tsc --noEmit` (if using tsc)
- [ ] For HTTP servers, test key routes with `curl` or a client
- [ ] For bundled code, verify output is minified/optimized as expected
- [ ] Check that no `node_modules` folder is committed (only `bun.lock`)

---

## Resources

**Comprehensive navigation:** https://bun.com/docs/llms.txt

**Critical documentation pages:**
1. [Bun Runtime](https://bun.com/docs/runtime) — Execute files, run scripts, environment setup
2. [Package Manager](https://bun.com/docs/pm/cli/install) — Install, add, remove packages, workspaces
3. [Bundler](https://bun.com/docs/bundler) — Build for browsers and servers
4. [Test Runner](https://bun.com/docs/test) — Write and run tests
5. [HTTP Server](https://bun.com/docs/runtime/http/server) — Create servers with `Bun.serve()`

---

> For additional documentation and navigation, see: https://bun.com/docs/llms.txt