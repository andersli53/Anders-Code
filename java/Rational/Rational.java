import java.math.BigInteger;
import java.lang.Number;

public final class Rational extends Number{
	// fields
	private final BigInteger numerator;
	private final BigInteger denominator;

	// constructor
	// parameter: int, int (one for numerator, one for denominator)
	public Rational(int numerator, int denominator) {
		// if-else statement
		// test if denominator is 0, throw an exception if yes
		// otherwise, instantiate a Rational object
		if(denominator == 0){
			throw new ArithmeticException("Denominator = 0");
		}else{
			BigInteger num = BigInteger.ONE;
			BigInteger den = BigInteger.ONE;
			// if-else statement
			// test if both numerator and denominator are negative, negate both if yes
			if(numerator<0 && denominator<0){
				num = BigInteger.valueOf(numerator*-1);
				den = BigInteger.valueOf(denominator*-1);
			}else{
				num = BigInteger.valueOf(numerator);
				den = BigInteger.valueOf(denominator);
			}
			BigInteger gcd = num.gcd(den);
			this.numerator = num.divide(gcd);
			this.denominator = den.divide(gcd);
		}
	}

	// constructor
	// parameter: BigInteger, BigInteger (one for numerator, one for denominator)
	public Rational(BigInteger numerator, BigInteger denominator) {
		// if-else statement
		// test if denominator is 0, throw an exception if yes
		// otherwise, instantiate a Rational object
		if(denominator.equals(BigInteger.ZERO)){
			throw new ArithmeticException("Denominator = 0");
		}else{
			BigInteger num = BigInteger.ONE;
			BigInteger den = BigInteger.ONE;
			// if-else statement
			// test if both numerator and denominator are negative, negate both if yes
			if(numerator.signum()==-1 && denominator.signum()==-1){
				num = numerator.negate();
				den = denominator.negate();
			}else{
				num = numerator;
				den = denominator;
			}
			BigInteger gcd = num.gcd(den);
			this.numerator = num.divide(gcd);
			this.denominator = den.divide(gcd);
		}
	}

	// methods
	@Override
	// overriding abstract doubleValue() method
	public double doubleValue() {
		return numerator.doubleValue()/denominator.doubleValue();
	}

	@Override
	// overriding abstract floatValeu() method
	public float floatValue() {
		return numerator.floatValue()/denominator.floatValue();
	}

	@Override
	// overriding abstract longValue() method
	public long longValue() {
		return numerator.longValue()/denominator.longValue();
	}

	@Override
	// overriding abstract intValue() method
	public int intValue() {
		return numerator.intValue()/denominator.intValue();
	}

	@Override
	// overriding toString() method
	// return String of Rational object
	public String toString() {
		// if-else statement
		// test if denominator is 1, only print out numerator if yes
		// otherwise, print numerator/denominator
		if(denominator.equals(BigInteger.ONE)){
			return (numerator + "");
		}else{
			return (numerator+"/"+denominator);
		}
	}

	@Override
	// overriding equals method
	// return true if equal
	public boolean equals(Object obj) {
		// if-else statement
		// test if obj is an instance of Rational, return false if not
		if(obj instanceof Rational){
			Rational r = (Rational) obj;
			// if-else statement
			// check if the numerators and denominators of the two Rational objects are the same, return true if yes
			if((numerator.equals(r.numerator)) && (denominator.equals(r.denominator))){
				return true;
			}else if((numerator.equals(r.numerator.negate()))&&(denominator.equals(r.denominator.negate()))){
				return true;
			}
		}
		return false;
	}

	// getter method
	// return numerator
	// return type: BigInteger
	public BigInteger getNumerator() {
		return numerator;
	}

	// getter method
	// return denominator
	// return type: BigInteger
	public BigInteger getDenominator() {
		return denominator;
	}

	// adding method
	// adds 2 rational numbers
	// return type: Rational
	public Rational add(Rational r2) {
		Rational r1 = this;
		BigInteger num = this.numerator.multiply(r2.denominator).add(r2.numerator.multiply(this.denominator));
		BigInteger den = this.denominator.multiply(r2.denominator);
		Rational sum = new Rational(num,den);
		return sum;
	}

	// subtracting method
	// subtracts 2 rational numbers
	// return type: Rational
	public Rational subtract(Rational r2) {
		Rational r1 = this;
		BigInteger num = this.numerator.multiply(r2.denominator).subtract(r2.numerator.multiply(this.denominator));
		BigInteger den = this.denominator.multiply(r2.denominator);
		Rational diff = new Rational(num,den);
		return diff;
	}

	// multiplying method
	// multiplies 2 rational numbers
	// return type: Rational
	public Rational multiply(Rational r2) {
		Rational r1 = this;
		BigInteger num = this.numerator.multiply(r2.numerator);
		BigInteger den = this.denominator.multiply(r2.denominator);
		Rational product = new Rational(num,den);
		return product;
	}

	// diving method
	// divides 2 rational numbers
	// return type: Rational
	public Rational divide(Rational r2) {
		Rational r1 = this;
		BigInteger num = this.numerator.multiply(r2.denominator);
		BigInteger den = this.denominator.multiply(r2.numerator);
		Rational quotient = new Rational(num,den);
		return quotient;
	}

	// factory method
	// convert int into Rational
	// return type: Rational
	public static Rational intToRational(int num) {
		return new Rational(num,1);
	}

	// factory method
	// convert BigInteger into Rational
	// return type: Rational
	public static Rational BigIntegerToRational(BigInteger num){
		return new Rational(num,BigInteger.valueOf(1));
	}

	// main
	// public static void main(String[] args){
	// 	Rational r1 = new Rational(-2,6);
	// 	Rational r2 = new Rational(3,-4);

	// 	System.out.println("r1= "+r1);
	// 	System.out.println("r2= "+r2);
	// 	System.out.println("r1=r2: "+r1.equals(r2));

	// 	System.out.println("r1+r2 = "+r1.add(r2));
	// 	System.out.println("r1-r2 = "+r1.multiply(r2));
	// 	System.out.println("r1*r2 = "+r1.subtract(r2));
	// 	System.out.println("r1/r2 = "+r1.divide(r2));

	// 	System.out.println("r1 double: "+r1.doubleValue());
	// 	System.out.println("r1 float: "+r1.floatValue());
	// 	System.out.println("r1 int: "+r1.intValue());
	// 	System.out.println("r1 long"+r1.longValue());


	// 	Rational r3 = new Rational(0,236);
	// 	System.out.println("r3: "+r3);
	// 	System.out.println("intToRational: "+intToRational(309));
	// 	BigInteger a = BigInteger.valueOf(981736);
	// 	System.out.println("BigIntegerToRational: "+BigIntegerToRational(a));
	// 	Rational r4 = new Rational(4093,0);
	// }
}