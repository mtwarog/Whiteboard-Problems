function unique(string) {
  presentChars = [];
  let isUnique = true;

  for (let i = 0; i < string.length; i++) {
    if (presentChars[string[i]]) {
      isUnique = false;
      break;
    } else {
      presentChars[string[i]] = true;
    }
  }

  return isUnique;
}

// Simple tests
if (!unique("symarop"))
  throw Error("Test 1 failed");
if (unique("symarops"))
  throw Error("Test 2 failed");
