function [ y ] = f1( x )
%evaluates the function: exp(-x) + 0.5*exp(-(x-4)^2)
y = exp(-x) + 0.5*exp((-1)*(x-4).^2);
end

