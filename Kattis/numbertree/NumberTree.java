import java.util.*;

class NumberTree {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		String height = input.split(" ")[0];
		String path = input.split(" ").length > 1 ? input.split(" ")[1] : "";
		
		int numberOfNodes = 0;
		for(int i = new Integer(height); i >= 0; i--) {
			numberOfNodes += Math.pow(2, i);
		}
		
		int index = 1;
		for(int i = 0; i < path.length(); i++) {
			if(path.charAt(i) == "L".charAt(0)) {
				index = 2*index;
			}
			if(path.charAt(i) == "R".charAt(0)) {
				index = 2*index + 1;
			}
		}
		System.out.println(numberOfNodes + 1 - index);
	}
}
// [-,7,6,5,4,3,2,1] => 
//  0 1 2 3 4 5 6 7
// node: i; parent: i/2; leftchild: 2i; rightchild: 2i+1;
// 
