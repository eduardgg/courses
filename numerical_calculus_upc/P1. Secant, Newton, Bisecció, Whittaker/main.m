%fa un plot dels logaritmes dels errors
[zeroB, errVB] = biseccio(1,2,100);
[zeroS, errVS] = secant(1,2,100);
[zeroN, errVN] = newton(1,100);
[zeroW, errVW] = whittaker(1,-26,100);
plot(1:100, log(errVB),1:100, log(errVN), 1:100, log(errVS), 1:100, log(errVW));
l= legend('biseccio','Newton','secant','Whittaker');