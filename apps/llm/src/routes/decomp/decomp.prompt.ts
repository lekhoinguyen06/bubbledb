export const prompts = {
    description: "Decompose the each sentence in the paragraph into source, relation, and target. Source and target are entities, and relation is the relationship between them.",
    notes: {
        aboutThePrompt: "The output format written in the prompt is [(source)(relation)(target), (source)(relation)(target), ...]. However, this is only used as an example. Consider other output schemas applied.",
    },
    rules: {
        identity: "For entities, if a name or identity is given, use it throughout the decomposition.",
        linguistic: "An entity can be a noun, pronoun, or noun phrase. A relation can be a verb, verb phrase, or prepositional phrase.",
        noLoop: "source and target cannot be the same entity.",
        singular: "If there are multiple sources, relations, or targets. Decompose to many sentences, each with one source, one relation, and one target.",
    },
    examples: {
        basic: "EXAMPLE: Nguyen loves apple. Apple is a fruit. Output: [(Nguyen)(loves)(apple), (Apple)(is)(a fruit)]",
        identityRule: "EXAMPLE: John is a teacher. He teaches math. Output: [(John)(is)(a teacher), (John)(teaches)(math)]",
        identityRuleViolation: "EXAMPLE: John is a teacher. He teaches math. Output: [(John)(is)(a teacher), (He)(teaches)(math)]",
        linguisticRule: "EXAMPLE: The cat sat on the mat. Output: [(The cat)(sat on)(the mat)]",
        noLoopRule: "EXAMPLE: The dog is a dog. Output: []",
        singularRule: "EXAMPLE: The cat and the dog both loves apple and banana. Output: [(The cat)(loves)(apple), (The cat)(loves)(banana), (The dog)(loves)(apple), (The dog)(loves)(banana)]",
    },
}