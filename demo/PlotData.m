
clear all
close all
load output/data.txt
data = data';

delta = data(1,:);
rho = data(2,:);
Q = data(3,:);

plot( delta, rho , delta , Q );
xlabel('delta');
ylabel('value');
legend('rho','Q');

