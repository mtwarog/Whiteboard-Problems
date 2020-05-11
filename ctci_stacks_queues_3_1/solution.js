class TripleStack {
  constructor() {
    this.memory = [];
    this.currentPeeks = [-3, -2, -1];
  }
  push(elem, stackId) {
    const currentPeek = this.currentPeeks[stackId - 1];
    this.memory[currentPeek + 3] = elem;
    this.currentPeeks[stackId - 1] += 3;
  }
  pop(stackId) {
    if (this.isEmpty(stackId)) {
      return null;
    }
    const currentPeek = this.currentPeeks[stackId - 1];
    const currentElem = this.memory[currentPeek];
    this.currentPeeks[stackId - 1] -= 3;
    return currentElem;
  }
  peek(stackId) {
    if (this.isEmpty(stackId)) {
      return null;
    }
    const currentPeek = this.currentPeeks[stackId - 1];
    const currentElem = this.memory[currentPeek];
    return currentElem;
  }
  isEmpty(stackId) {
    return this.currentPeeks[stackId - 1] === stackId - 1 - 3;
  }
}

// Simple tests
function testPushAddsElementGivenElementAndStackId() {
  const triStack = new TripleStack();
  const elem = {};
  triStack.push(elem, 1);
  const peekElem = triStack.peek(1);
  const isElemOnPeek = Object.is(elem, peekElem);
  if (!isElemOnPeek) {
    throw new Error("Element was not pushed on stack");
  }
}
function testPopReturnsElementGivenElementAndStackId() {
  const triStack = new TripleStack();
  const elem = {};
  triStack.push(elem, 1);
  const poppedElem = triStack.pop(1);
  const wasElemPopped = Object.is(elem, poppedElem);
  if (!wasElemPopped) {
    throw new Error("Element was not popped from stack");
  }
}
function testIsEmptyReturnsFalseGivenEmptyStack() {
  const triStack = new TripleStack();
  const isEmpty = triStack.isEmpty(1);
  if (!isEmpty) {
    throw new Error("Stack is empty, but isEmpty returns false");
  }
}
testPushAddsElementGivenElementAndStackId();
testPopReturnsElementGivenElementAndStackId();
testIsEmptyReturnsFalseGivenEmptyStack();

// Example of usage
function example() {
  const triStack = new TripleStack();
  triStack.push("red", 1);
  triStack.push("green", 2);
  triStack.push("silver", 2);
  triStack.push("blue", 3);
  triStack.push("gold", 3);
  console.log("red: " + triStack.pop(1));
  console.log("silver: " + triStack.pop(2));
}

module.exports = TripleStack;
