function unique(string) {
  let isUnique = true;
  check:
  for (let i = 0; i < string.length; i++) {
    for (let j = 0; j < string.length; j++) {
      if (i !=j && string[i] == string[j]) {
        isUnique = false;
        break check;
      }
    }
  }
  return isUnique;
}

// Simple tests
if (!unique("symarop"))
  throw Error("Test 1 failed");
if (unique("symarops"))
  throw Error("Test 2 failed");
