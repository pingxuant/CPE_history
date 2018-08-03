
//uva10254
import java.math.BigInteger;
import java.util.Scanner;

public class p10254{
	
	public static void main(String[] args) {
		final int Max = 10001;
		Scanner scanner = new Scanner(System.in);
		BigInteger[] han = new BigInteger [Max];
		BigInteger[] two = new BigInteger [Max];
		int[] k = new int [Max];
		
		two[0] = BigInteger.valueOf(0);
		two[1] = BigInteger.valueOf(1);
		han[0] = BigInteger.valueOf(0);
		han[1] = BigInteger.valueOf(1);
		k[1] = 0;
		for(int i = 2; i < Max; i++) {
			two[i] = BigInteger.valueOf(2).multiply(two[i-1]).add(BigInteger.valueOf(1));
			han[i] = BigInteger.valueOf(0);
			k[i] = 0;
		}
		
		for(int n = 2; n < Max; n++) {
			int tk = k[n-1];
			han[n] = han[tk].multiply(BigInteger.valueOf(2)).add(two[n-tk]); 
			for( ; tk <= n; tk++) {
				BigInteger tmp = han[tk].multiply(BigInteger.valueOf(2)).add(two[n-tk]);
				
				if(tmp.max(han[n]).equals(han[n]))
					han[n] = tmp;
				else {
					k[n] = tk - 1;
					break;
				}
			}
		}
		
		while(scanner.hasNextInt()) {
			int n = scanner.nextInt();
			System.out.println(han[n].toString());
		}
	}
}