# bubbledb

Graph Vector DB

## Vision

What if we decompose semantic vectors to capture relationship, rather than just similarity?

## Example

From a dataset:

```txt
Anne is in love with Ben. 
Cecile & Dakota are sisters. 
Anne & Cecile has the same mother.
```

Using some tiny llm, we can decompose to:

```txt
(Anne)(is in love with)(Ben)
(Cecile)(is sister)(Dakota)
(Anne)(has same mother with)(Cecile)
```

What if an agent can just query "Find An who loves Dennis where Dennis is a friend of Cece and Cece is An's sister"?

```json
{
    "entity": "Anne",
    "relates": {
        "love": [
            {
                "entity": "Ben",
                "relates": {}
            },
        ],
        "is sister": [
            {
                "entity": "Cecilia",
                "relates": {}
            }
            {
                "entity": "Dakota",
                "relates": {}
            }
        ]
    }
}
```

## Benefits

- Loose entities

- Loose edges

- Loose queries

- Extract relations

## Usecases

- Agentic query

- Analytics

## Challenges

This idea has big usability concerns. We don't really knows whether anyone need this or whether a "loose" database is even practical. But we want to find out.
