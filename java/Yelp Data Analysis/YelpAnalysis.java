package hw5;

import java.io.*;
import java.lang.Throwable.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Collections;
import java.util.Comparator;
// import java.util.concurrent.TimeUnit;


public class YelpAnalysis{
	
	// public static method
	// calculate term frequency in a business' review
	// parameter: Business; return: Map<String,Integer>
	public static Map<String,Integer> wordFreq(Business b){
		Map<String,Integer> wordFreq = new HashMap<String,Integer>();
		String[] strings = b.reviews.split("\\s+");
		// for loop
		// loop trhough String array to calculate term frequency
		for(String word: strings){
			// if-else statement
			// insert (word,1) if word hasn't been added, else increment frequency by 1
			if(!wordFreq.containsKey(word)){
				wordFreq.put(word,1);
			}else{
				int c = wordFreq.get(word);
				c = c + 1;
				wordFreq.put(word,c);
			}
		}

		return wordFreq;
	}

	// public static method
	// calculate document frequency of each word in a business' review
	// parameters: Map<String,Integer>, Business;
	public static void docFreq(Map<String,Integer> map, Business b){
		Map<String,Integer> wordFreq = new HashMap<String,Integer>();
		wordFreq = wordFreq(b);
		// for loop
		// loop through each word in wordFreq's keySet to calculate document frequency of each word
		for(String word: wordFreq.keySet()){
			// if-else statement
			// insert (word,frequency) pair to map passed as parameter if word frequency is greater than 1
			if(wordFreq.get(word)>0){
				// if-else statement
				// insert (word,1) if word hasn't been added, else increment frequency by 1
				if(!map.containsKey(word)){
					map.put(word,1);
				}else{
					int c = map.get(word);
					c = c + 1;
					map.put(word,c);
				}
			}
		}
		
	}

	// public static method
	// calculate term-frequency-inverse-document-frequency
	// parameters: Map<String,Integer>, Business; return: Map<String,Double>
	public static Map<String,Double> tf_idf(Map<String,Integer> docFreq, Business b){
		Map<String,Integer> wordFreq = new HashMap<String,Integer>();
		Map<String,Double> tfidf_map = new HashMap<String,Double>();
		wordFreq = wordFreq(b);
		// for loop
		// loop through each word in wordFreq's keySet to calculate tf-idf
		for(String word: wordFreq.keySet()){
			// if-else statement
			// calculate tf-idf if docFreq contains word in wordFreq
			if(docFreq.containsKey(word)){
				// if-else statement
				// calculate tf-idf if word appears in at least 5 documents, else assign tf-idf of that word to be 0
				if(docFreq.get(word)>=5){
					double tfidf = (double) wordFreq.get(word)/docFreq.get(word);
					tfidf_map.put(word,tfidf);
				}else{
					tfidf_map.put(word,0.0);
				}
			}
		}
		return tfidf_map;
	}

	// public static method
	// sort tf-idf map in ascending order
	// parameter: ArrayList<Map.Entry<String,Double>>
	public static  void sortByTFIDF(ArrayList<Map.Entry<String,Double>> tfidf_list){
		Collections.sort(tfidf_list, new Comparator<Map.Entry<String,Double>>(){
			@Override
			public int compare(Map.Entry<String,Double> m1, Map.Entry<String,Double> m2){
				return m2.getValue().compareTo(m1.getValue());
			}
		});
	}

	// public static method
	// print tf-idf map up to n elements
	// parameters: ArrayList<Map.Entry<String,Double>>, int
	public static void printTFIDF(ArrayList<Map.Entry<String,Double>> tfidf_list, int n){
		String listOfTFIDF = "";
		// for loop
		// print first n elements of the ArrayList
		for(int i=0; i<n; i++){
			listOfTFIDF += "("+tfidf_list.get(i).getKey()+","+tfidf_list.get(i).getValue()+") ";
		}
		System.out.println(listOfTFIDF);
	}

	// main function
	public static void main(String[] args) throws Throwable{

		// long startTime = System.nanoTime();

		String text = "";
		BufferedReader reader = new BufferedReader(new FileReader("yelp_Dataset/yelpDatasetParsed_full.txt"));
		ArrayList<Business> businessList = new ArrayList<>();
		Map<String,Integer> wordFreqDocCount = new HashMap<String,Integer>();

		// while loop
		// continuously reading next line of the file and add each business into an ArrayList of business until end of file
		while(true){
			text = reader.readLine();
			// if-else statement
			// break loop if no more business to read from
			if(text==null){
				break;
			}
			// text = text.substring(1,text.length()-1);
			text = text.replaceAll("\\{","");
			text = text.replaceAll("\\}","");
			String[] arr_biz = text.split(",");
			Business business = new Business(arr_biz);
			businessList.add(business);
			// if-else statement
			// break loop if no more business can be added
			if(business==null){
				break;
			}
		}

		// for loop
		// loop through each business from businessList and calculate each word's document frequency
		for(Business b: businessList){
			docFreq(wordFreqDocCount,b);
		}

		// sort businessList in ascending order based on number of characters in review
		Collections.sort(businessList);

		// for loop
		// print out first 10 business in sorted businessList and tf-idf of the top 30 words with highest tf-idf scores
		for(int i=0; i<10; i++){
			// Business currentBusiness = businessQueue.remove();
			Map<String,Double> tfidf_map = new HashMap<String,Double>();
			tfidf_map = tf_idf(wordFreqDocCount,businessList.get(i));

			ArrayList<Map.Entry<String,Double>> tfidf_list = new ArrayList<>(tfidf_map.entrySet());
			sortByTFIDF(tfidf_list);
			System.out.println(businessList.get(i));
			printTFIDF(tfidf_list,30);
		}

		// long endTime = System.nanoTime();

		// long timeElapsed = endTime - startTime;
		// double seconds = (double) timeElapsed/1_000_000_000.0;

		// System.out.println("\n"+"Time Elapsed: "+seconds);
	}

	
}