class CharCountSolution {
  public static void main(String[] args) {
    CharCountSolution charCountSolution = new CharCountSolution();

    // Verify solution
    boolean solution1 = charCountSolution.solve("straw", "artsw");
    boolean solution2 = charCountSolution.solve("straw", "seqfw");
    System.out.println(solution1);
    System.out.println(solution2);
    assert (solution1 == true);
    assert (solution2 == false);
  }
  private boolean solve(String s, String t) {
    if (s.length() != t.length()) {
      return false;
    }

    int[] letters = new int[128];

    char[] s_array = s.toCharArray();
    for (char c : s_array) {
      letters[c]++;
    }

    for (int i = 0; i < t.length(); i++) {
      int c = (int) t.charAt(i);
      letters[c]--;
      if (letters[c] < 0) {
        return false;
      }
    }

    return true;
  }
}
