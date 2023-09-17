
import java.util.*;
public class Main {


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
		int[] check = new int[26];
		int chk = 1;
		int max = 0;
		int count = 0;

		String str = sc.next();
		str = str.toUpperCase();

		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < alphabet.length(); j++) {
				if (str.charAt(i) == alphabet.charAt(j)) {
					check[j] += chk;
				}
			}
		}
		int pos = 0;
		//max:여기 최대값을저장 pos: 인덱스값
		for (int i = 0; i < check.length; i++) {
			if (max < check[i]) {
				max = check[i];
				pos = i;
			}
		}
		for (int i = 0; i < check.length; i++) {
			if (max==check[i]) {
				count++;
			}
		}
		if (count >= 2) {
			pos = 26;
		}
		System.out.println(alphabet.charAt(pos));
	}
}