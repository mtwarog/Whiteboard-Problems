class SortingSolution {
  public static void main(String[] args) {
    SortingSolution sortingSolution = new SortingSolution();

    // Verify solution
    boolean solution1 = sortingSolution.solve("straw", "artsw");
    boolean solution2 = sortingSolution.solve("straw", "seqfw");
    System.out.println(solution1);
    System.out.println(solution2);
    assert (solution1 == true);
    assert (solution2 == false);
  }
  private boolean solve(String s, String t) {
    if (s.length() != t.length()) {
      return false;
    }
    return sort(s).equals(sort(t));
  }
  private String sort(String s) {
    char[] content = s.toCharArray();
    java.util.Arrays.sort(content);
    return new String(content);
  }
}
