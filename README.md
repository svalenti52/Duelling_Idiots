# Duelling_Idiots

Duelling Idiots Problems by Paul Nahin

Compiled with
g++ -std=c++14

Chapter 1. How to Ask an Embarrassing Question

    This considers the sensitive subject of how to ask an embarrasing
    question so no one's privacy is violated (a yes/no question). One
    can do this by introducing probability into the picture: Have a
    fair coin, and follow this procedure (and no one apart from 
    participant sees the results of the coin toss) - flip the coin once,
    and if it is tails answer the question honestly; if it is heads,
    flip the coin again and answer the question according to the coin.
    We can test this by Monte Carlo method using Nahin's formula or his
    numbers presented in the book.
    
    Associated file: embarrassing.cpp.

Chapter 2. When Idiots Duel

    The duel between two contestants takes two forms. The first form
    is simple alternation of a single shot (first one takes a shot, then
    the other). The objective is to find the probability of the first
    duellist surviving. The other form is the same except for incrementing
    the number of shots a duellist has on each turn, i.e., A takes one shot,
    B takes two shots, A takes three shots, etc. until the duel is finished.
    We have the same objective as before.

    Associated files: duel1.cpp, duel2.cpp, duel3.cpp
    
Chapter 3. Will the Light Bulb Glow?

    A sequence of switches is arranged in three layers so that the
    top layer is a serially connected sequence of N switches, comprised 
    of a middle layer of N switches connected in parallel each of which
    is comprised of a low layer of N switches connected in series. Note
    that each of layers has the same number of switches. A series of
    switches is considered closed when all of the switches making up the
    series are closed. Switches in parallel are closed if any of the
    switches are closed. We are to determine the probability that the
    light bulb glows (i.e., the circuit comprised of the above switches
    is closed) given the number of switches and the individual probability
    of single switch being closed (which applies to all the individual
    switches in the layered arrangement).
    
    Associated files: glow.cpp, glow1.cpp, and glow2.cpp.
    
Chapter 4. The Underdog and the World Series

    Associated file: baseball.cpp.

Chapter 5. The Curious Case of the Snowy Birthdays

    Associated files: snow1.cpp, snow2.cpp, and snow3.cpp.

Chapter 6. When Human Flesh Begins to Fail

Chapter 7. Baseball Again, and Mortal Flesh, Too

Chapter 8. Ball Madness

Chapter 9. Who Pays for the Coffee?

Chapter 10. The Chess Champ versus the Gunslinger

Chapter 11. A Different Slice of Probabilistic Pi

Chapter 12. When Negativity is a No-No

Chapter 13. The Power of Randomness

Chapter 14. The Random Ratio

    A capacitor discharging in the presence of resistance and an inductor
    will either decay monotonically or with oscillations (an RLC circuit).
    The characteristic (quadratic) equation associated with the second
    order differential equation of the RLC circuit has a transient response
    that decays according to whether the discriminant is positive or
    negative. It decays monotonically if it is positive, it oscillates if
    negative.
    
    Consider the partially random quadratic formula x^2 + Bx + C = 0. This
    is a monic polynomial (leading coefficient is one). What is the
    probability, if B and C are uniformly, and independently, randomly
    chosen from the unit interval, that the discriminant is positive?
    
    Now consider the same question for the totally random quadratic formula:
    Ax^2 + Bx + C =0. Divide through by A and then consider the discriminant
    (i.e., is (B/A)^2 > 4(C/A)?).
    
    Associated file: osc_limit.cpp.

Chapter 15. An Inconceivable Difficulty

Chapter 16. The Unsinkable Tub is Sinking! How to Find Her, Fast

Chapter 17. A Walk in the Garden

Chapter 18. Two Flies Stuck on a Piece of Flypaper - How Far Apart?

Chapter 19. The Blind Spider and the Fly

Chapter 20. Reliably Unreliable

Chapter 21. When Theory Fails, There is Always the Computer
