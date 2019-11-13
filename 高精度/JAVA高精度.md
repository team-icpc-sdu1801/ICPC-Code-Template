Java高精度
----------

``` {language="java"}
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        BigInteger a1 = new BigInteger("1"), a2 = new BigInteger("2"), ans;
        ans = a1.mod(a2);
        ans = a1.add(a2);
        ans = a1.subtract(a2);
        ans = a1.multiply(a2);
        ans = a1.divide(a2);
        System.out.println(ans);
        BigDecimal b1 = new BigDecimal(1), b2 = new BigDecimal(2), res;
        res = b1.add(b2);
        res = b1.subtract(b2);
        res = b1.multiply(b2);
        res = b1.divide(b2, 10, BigDecimal.ROUND_HALF_UP);/*保留10位，并四舍五入*/
        System.out.println(res);
    }
}
```
