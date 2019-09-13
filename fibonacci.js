// USAGE: node fibonacci.js n
const args = process.argv.slice(2);
const n = args[0];
function fibonacci(n) {
  return n <= 1 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}
console.log(fibonacci(n));
