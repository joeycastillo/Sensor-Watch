# flowtime for sensor-watch

## What is flowtime?

flowtime is an art project and thought experiment that challenges and reimagines our traditional understanding of time. It explores the relationship between our perception of time and our ability to enter [flow states](1), periods of deep focus and engagement with the present moment. In essence, flowtime is a manifestation of timelessness.

The concept emerged from a simple observation: whenever I became aware of time, whether by mechanically looking at my watch or involuntarily catching a glimpse of a screen, I momentarily and unconsciously time travel and lose touch with the present. This sparked a question: what if there were a way to decide consciously whether to know the time or remain immersed in the flow? This was the birth of flowtime.

Although it preserves the familiar structure of 24 hours per day 60 minutes per hour, the order of its hours and minutes is unpredictable and unique each day. Yet it remains universal, meaning the flowtime is the same for everyone, just like conventional time. This uncertainty encourages us to loosen our attachment to time, creating an opportunity to return into the flow of the present moment.

What started as a conceptual exploration has since materialized into a tangible, interactive technology that melds philosophical inquiry with practical application. It is now available in the form of a JavaScript library, a command line tool, a classic Casio watch, and on the [flowtime project website](7).

Concept and development by [Lionel Ringenbach (a.k.a. Ucodia)](6), started in September 2017.

## How does it work?

To compute the flowtime, the current date and time is used as input. The day and hour periods are derived by concatenating their numerical values. For example, `July 21 2018 09:28:42` has identifiers `20180721` for the day period and `2018072109` for the hour period. These identifiers then seed a [pseudorandom number generator (PRNG)](2) to produce a deterministic sequence of hours and minutes. This method ensures universality while remaining unpredictable to human beings.

The [xorshift32 algorithm](3) generates the random numbers, and the [Fisher-Yates algorithm](4) shuffles them, resulting in deterministically random sequences.

## Useful references

- [Flow state](1) on Wikipedia
- [Pseudorandom number generator](2) on Wikipedia
- [Xorshift](3) on Wikipedia
- [Fisher-Yates shuffle](4) on Wikipedia
- [Sensor Watch](5) official website
- [Lionel Ringenbach (a.k.a. Ucodia)](6) official website
- [flowtime](7) project official website

[1]: https://en.wikipedia.org/wiki/Flow_(psychology)
[2]: https://en.wikipedia.org/wiki/Pseudorandom_number_generator
[3]: https://en.wikipedia.org/wiki/Xorshift
[4]: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
[5]: https://www.sensorwatch.net/
[6]: https://ucodia.space
[7]: https://ucodia.space/flowtime