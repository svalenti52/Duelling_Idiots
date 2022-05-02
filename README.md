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

    Given that the stronger team has a probability p, (p > .5), of winning,
    what is the probability that the weaker team wins the seven game series?
    Also, give the probability profile of the series length (for 4 through 7).

    Associated file: baseball.cpp.

Chapter 5. The Curious Case of the Snowy Birthdays

    Actually three different methods of approximating e and one method of
    approximating pi. 
    
    1) Divide the unit interval into A equal-sized intervals (in snow1.cpp,
    200,000 is selected for A).  Then randomly generate A numbers, fitting them
    into the appropriate interval based on the value being within the interval.
    Let I(0) be the count of intervals containing 0 of the random numbers.
    The ratio A/I(0) will approximate the value of e.
    snow1_1.cpp speeds up the process by randomly selecting 1,000,000 numbers
    from [0,999999] and incrementing the count according to the number chosen.
    
    2) From the unit interval, count a sequence of randomly selected real numbers
    till their sum exceeds 1. A large number of such sequences will find that the
    count approximately averages to e.

    3) Subdivide the unit interval by the following method: pick a random number from
    the unit interval and let that form the right edge of the left subinterval; then
    repeat the process substituting the new left subinterval for the unit interval.
    Obviously each subsequent left subinterval becomes smaller than the previous
    left subinterval. Do this about 10 or 20 times, then take the sum of subsequent
    right edges of these left subintervals. Plotting the CDF of this sum, observe
    that it is approximately linear in the unit interval. In the text is given that
    the slope is equal to e^(-gamma) (Euler's number followed by Euler's constant).

    4) Inscribe a circle within the unit square. Then pick points at random within
    the square (represent the number of points in the square by S) and determine
    whether it is also contained within the circle (represent the number of points
    in the circle by C). The value C/S * 4 will approximate pi.

    Associated files: snow1.cpp, snow1_1.cpp, snow2.cpp, snow3.cpp, and snow_pi.cpp.

Chapter 6. When Human Flesh Begins to Fail

Chapter 7. Baseball Again, and Mortal Flesh, Too

Chapter 8. Ball Madness

    Initially, one urn contains all black balls, the other urn contains all white
    balls.  Then at subsequent time intervals (labeled i = 1, 2, ...), a ball is
    selected randomly from each urn and placed in the other urn (in other words
    "exchanged").  Obviously at i = 1, this results in one black ball being placed
    in the previously all white urn and vice versa.  For subsequent values of i,
    the color of ball is dependent on which ball is randomly selected from the
    urn.  The objective is to graph the number of black balls as function of i.
    How rapidly does the proportion of black balls in urn 1 approach 0.5 as a
    function of N, the total number of black balls in urn 1 at i = 0?  Also, how
    does the proportion vary as a function of N?

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
