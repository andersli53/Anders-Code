import java.lang.Math;


public class MyMath_Modified{
	/*
	// fields
	public static double num = 0.0;
	public static double upper = 1.0;
	public static double lower = 0.0;
	public static double middle = 0.0;
	public static double error = Math.pow(10,-10);
	*/

	// member function sqrt
	// parameter: double; return: double
	// uses bisection to calculate square root of a number
	public static double sqrt(double d){
		double num = 0.0;
		double upper = 1.0;
		double lower = 0.0;
		double middle = 0.0;
		double error = Math.pow(10,-10);

		num = d;
		// if-else statement
		// checks whether lower <= sqrt(num) <= upper
		if(lower*lower <= num && num <= upper*upper){
			// while loop
			// loops bisection algorithm on num until error <= 10^(-10) 
			while(upper - lower > error){
				middle = (lower+upper)/2;
				// if-else statement
				// checks whether sqrt(num) is in [lower,middle] or [middle,upper]
				if (num <= middle*middle){
					upper = middle;
				}
				else{
					lower = middle;
				}
			}
			num = middle;
		}
		else if(num > 1){
			double n = 1;
			double temp = num/4;
			// while loop
			// loops normalization of input until num/4^n <= 1
			while (temp > 1){
				n = n + 1;
				temp = num/Math.pow(4,n);
			}
			// while loop
			// loops bisection algorithm on temp until error <= 10^(-10)
			while (upper - lower > error){
				middle = (lower+upper)/2;
				// if-else statement
				// checks whether sqrt(num) is in [lower,middle] or [middle,upper]
				if(temp <= middle*middle){
					upper = middle;
				}
				else{
					lower = middle;
				}
			}
			temp = middle;
			num = Math.pow(2,n)*temp;
		}
		
		return num;
	}

	

	public static void main(String[] args){

		// System.out.println(MyMath.sqrt(0.5)); // 0.7071067811865476
		// System.out.println(MyMath.sqrt(0.21117703599733928)); // 0.45954002654539167
		// System.out.println(MyMath.sqrt(0.8355043824178474)); // 0.9140592882400175
		// System.out.println(MyMath.sqrt(0.6564575045382239)); // 0.8102206517598919
		// System.out.println(MyMath.sqrt(0.37453357648678265)); // 0.6119914839985787
		// System.out.println(MyMath.sqrt(0.8628256146099504)); // 0.9288840695210304
		// System.out.println(MyMath.sqrt(0.41292145921042755)); // 0.6425896507184251 
		// System.out.println(MyMath.sqrt(0.5436976754191907)); // 0.7373585799454636

		int num_rand = 10000000;

		// calculate total time for generating 10,000,000 random numbers
		long rand_gen_time = 0;
		long rand_gen_start = System.currentTimeMillis();
		// for loop
		// generate 10,000,000 random numbers within [0,100]
		for (int i = 0; i < num_rand; i++){
			double rand_num = 100*Math.random();
		}
		long rand_gen_end = System.currentTimeMillis();
		rand_gen_time = rand_gen_end - rand_gen_start;

		// calculate total time for Math.sqrt + random number generation
		long math_time = 0;
		long math_start = System.currentTimeMillis();
		// for loop
		// run Math.sqrt on 10,000,000 random numbers
		for (int i = 0; i < num_rand; i++){
			Math.sqrt(100*Math.random());
		}
		long math_end = System.currentTimeMillis();
		math_time = math_end - math_start;

		// calculate total time for MyMath.sqrt + random number generation
		long mymath_time = 0;
		long mymath_start = System.currentTimeMillis();
		// for loop
		// run MyMath.sqrt on 10,000,000 random numbers
		for (int i = 0; i < num_rand; i++){
			MyMath.sqrt(100*Math.random());
		}
		long mymath_end = System.currentTimeMillis();
		mymath_time = mymath_end - mymath_start;

		System.out.println("Time used by Math.sqrt: " + ((double) math_time-rand_gen_time)/num_rand);
		System.out.println("Time used by MyMath.sqrt: " + ((double) mymath_time-rand_gen_time)/num_rand);

	}
}