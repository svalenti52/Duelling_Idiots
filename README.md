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

    4) Inscribe a circle centered at the origin within a 2x2 square (the radius of
    the circle is 1). Then pick points at random within the quarter square that
    contains the unit interval for the x and y axes. Let S represent the total count
    of random points.  Let C represent the count of the of the subset of points that
    also fall within the circle (this section of the circle has area pi/4).
    The value C/S * 4 will approximate pi.

    Associated files: snow1.cpp, snow1_1.cpp, snow2.cpp, snow3.cpp, and snow_pi.cpp.

Chapter 6. When Human Flesh Begins to Fail

    N people are flipping independent fair coins n times each. What is the probability
    that they all have the same number of heads come up?
    Calculate for N = 2, 3, 4 and n = 10, 50, 100, 150.
    The title of the chapter is due to the "overwhelming" amount of number-crunching
    required to do the problem without a computer.

    Associated files: sameflips.cpp

Chapter 7. Baseball Again, and Mortal Flesh, Too

    Given that a baseball has a probability p of winning a single game (a simplifying
    assumption for sure), what is the probability of winning 81p games after half a
    season (assuming a 162 game season)? The same question applies for winning 162p
    games for a full season. For p = .01, .02, .., 1.0, graph the ratio of
    81p / 162p, explaining the unexpected strangeness of the graph.

    Associated files: bbseason.cpp

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

    Associated files: ball.cpp

Chapter 9. Who Pays for the Coffee?

    This a form of odd-man out, i.e., N people each simultaneously flip a
    a coin and if there is single head or tail among them, that person
    has to pay for coffee for all. How many simultaneous flip events on
    average are required to determine the payer? A further question is
    supposing there is one person with an unfair coin: how does this affect
    the outcome?

    Associated files: coffee.cpp

Chapter 10. The Chess Champ versus the Gunslinger

    What a difference a draw makes! What is the probability that a chess
    champ wins a 6 game match? Or ties it? This is oddly difficult for
    an analytical solution even though it seems that it should be simple.

    Associated files: champ.cpp

Chapter 11. A Different Slice of Probabilistic Pi

    This is a needle and circular table top problem: randomly dropping a
    needle onto the table top, what is the probability that one end of the
    needle sticks out over the edge of the table top? Also consider the
    other two events: that of two ends protruding and that of the needle
    being completely contained by the interior of the table top.

    Associated files: needle.cpp

Chapter 12. When Negativity is a No-No

    What is the PDF of Z = X / (X - Y) where X and Y are uniformly distributed
    random variables on the unit interval?

    Associated files: negativity.cpp

Chapter 13. The Power of Randomness

    What is the PDF of Z = X ^ Y where X and Y are uniformly distributed
    random variables on the unit interval?

    Associated files: power.cpp

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

    Given a probability p of having a boy (1 - p = q is the corresponding
    probability of having a girl), how many children are expected till a
    subsequent child matches the sex of first? What does the graph look
    like for p in the range [0, 0.01, ..., 1.0]?

    Associated file: inconceivable.cpp

Chapter 16. The Unsinkable Tub is Sinking! How to Find Her, Fast

    A radio distress signal was received from a ship that it was near one
    of two islands (North and South). N rescue ships are sent,
    each with an individual probability s of finding the ship. Note that s
    is fixed and the search is independent for each ship. The problem
    is that of allocating a number of ships to each island as a function
    of the probability that the distressed ship is at that island. For
    [0, 0.01, 0.02, ..., 1.0] being the probability of the distressed ship
    being at the North island, determine the allocation that maximizes the
    probability the distressed ship will be found. Calculate for N = 13, s
    = 0.2; N = 40, s = 0.2; N = 40, s = 0.5.

    Associated file: tub.cpp

Chapter 17. A Walk in the Garden

    Don't know where the title came from on this one.
    Consider the unit square with one side placed along the x-axis, aligned
    with the [0, 1] segment.
    Select two random real numbers, one from the range [0, 1], the other
    from the range [0, pi]. Label the first random number 'x' and the second
    'ang'.  Locate x on the x-axis (along one side of the unit square) and then
    take the line segment at an angle of ang at x, terminating where it intersects
    with the other edge of the unit square. The length of the resulting segment
    is the item of interest. Generate 100,000 of these random pairs (x, ang) and
    form a histogram of the counts of the segments lengths (show the PDF and CDF).

    Associated file: garden.cpp

Chapter 18. Two Flies Stuck on a Piece of Flypaper - How Far Apart?

    Two flies land at random on a unit square.  What is the probability that
    they are greater that 1 unit apart? The same question is also asked for
    the circle of area 1 (hence radius of 1/sqrt(pi)).

    Associated files: fly_sqr.cpp, fly_crcl.cpp

Chapter 19. The Blind Spider and the Fly

    A blind spider has a strange kind of web represented by a set of states
    and transitions (specifically 8 states or "places" on the web). A fly lands
    on the web becoming stuck; it dies for some reason, so the spider has to randomly
    search for the fly.  Given that the fly is in state 1 and the spider starts
    in state 0, and given the following set of transitions, what is the expected
    number of transitions that the spider will make till it reaches the fly?
    State 0 transitions to 3, 6, 7 (spider begins search here)
    State 1 transitions to 2, 8 (fly is here)
    State 2 transitions to 1, 4, 7
    State 3 transitions to 0
    State 4 transitions to 2, 5
    State 5 transitions to 4, 6
    State 6 transitions to 0, 5, 7
    State 7 transitions to 0, 2, 6, 8
    State 8 transitions to 1, 7

    Associated files: blind_spider.cpp, blind_spider1.cpp, blind_spider_MCS.cpp

Chapter 20. Reliably Unreliable

    This problem deals with the probability of electronic system failure and
    schemes with multiple electronic systems that provide redundancy in an
    attempt to reduce the chances of failure.
    Given is the probability of single system failure by time T:  1 - e^(-aT)
    where 'a' is a positive constant characteristic of the system. This
    problem compares the performance of one system and three systems (where
    majority rule is then observed, if one system fails, the other two still
    provide the correct feedback for decision making). Also assume a = 1/100
    and compare results for T = [0, 200].

    Associated file: reliable.cpp

Chapter 21. When Theory Fails, There is Always the Computer

    This problem has to with a probabilistic pert chart (one of my least
    favorite topics, due to experience with Microsoft Project).
    Given a certain set of tasks and possible times to complete, plot a
    critical likelihood for each task. Also plot a histogram of project
    completion counts.

    Associated file: pert.cpp
