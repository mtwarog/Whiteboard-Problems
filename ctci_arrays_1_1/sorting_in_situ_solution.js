function unique(string) {
  let isUnique = true;
  string = string.split('').sort();

  if (string.length > 1) {
    for (let i = 0; i < string.length - 1; i++) {
      if (string[i] == string[i+1]) {
        isUnique = false;
        break;
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
