const resultsCache = [1,1];
function fib(n) {
  if (resultsCache[n])
    return resultsCache[n];
  fibN = fib(n-1) + fib(n-2);
  resultsCache[n] = fibN;
  return fibN;
}
