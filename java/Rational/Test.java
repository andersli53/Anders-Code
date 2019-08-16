import java.math.BigInteger;
public class Test{
	public static void main(String[] args) {
			Rational r1 = new Rational(-2,6);
			Rational r2 = new Rational(3,-4);

			System.out.println("r1= "+r1);
			System.out.println("r2= "+r2);
			System.out.println("r1=r2: "+r1.equals(r2));

			System.out.println("r1+r2 = "+r1.add(r2));
			System.out.println("r1-r2 = "+r1.multiply(r2));
			System.out.println("r1*r2 = "+r1.subtract(r2));
			System.out.println("r1/r2 = "+r1.divide(r2));

			System.out.println("r1 double: "+r1.doubleValue());
			System.out.println("r1 float: "+r1.floatValue());
			System.out.println("r1 int: "+r1.intValue());
			System.out.println("r1 long"+r1.longValue());


			Rational r3 = new Rational(0,236);
			System.out.println("r3: "+r3);
			System.out.println("intToRational: "+r3.intToRational(309));
			BigInteger a = BigInteger.valueOf(981736);
			System.out.println("BigIntegerToRational: "+ r3.BigIntegerToRational(a));
			Rational r4 = new Rational(3531,1253);

			System.out.println(r4.getNumerator());
			System.out.println(r4.getDenominator());
		}
}
