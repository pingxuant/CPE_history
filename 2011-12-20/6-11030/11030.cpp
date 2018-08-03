
//uva11030
import java.util.Scanner;
import java.awt.Polygon;

public class p11030 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t, ti = 0;
		t = scanner.nextInt();
		while(ti++ < t) {
			int n;
			Polygon[] p = new Polygon [20];
			
			n = scanner.nextInt();
			for(int i = 0; i < n; i++) {
				int s = scanner.nextInt();
				int[] px = new int [20];
				int[] py = new int [20];

				for(int j = 0; j < s; j++) {
					px[j] = scanner.nextInt();
					py[j] = scanner.nextInt();
				}
				p[i] = new Polygon(px, py, s);

			}
			System.out.println("Case " + ti + ":");
			
			int s = scanner.nextInt();
			
			for(int i = 0; i < s; i++) {
				int sx = scanner.nextInt();
				int sy = scanner.nextInt();
				int ex = scanner.nextInt();
				int ey = scanner.nextInt();
				int cnt = 0;
				
				for(int j = 0; j < n; j++) {
					if(p[j].contains(sx, sy) != p[j].contains(ex, ey))
						cnt++;
				}
				
				System.out.println(cnt);
			}
			
		}
	}
}
