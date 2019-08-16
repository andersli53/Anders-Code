package hw5;

public class Business implements Comparable<Business>{
  String businessID;
  String businessName;
  String businessAddress;
  String reviews;
  int reviewCharCount;

  // constructor
  // parameter: String[]
  public Business(String[] businessArray){
    this.businessID = businessArray[0];
    this.businessName = businessArray[1];
    this.businessAddress = businessArray[2];
    this.reviews = businessArray[3];
    this.reviewCharCount = this.reviews.toCharArray().length;
  }
  
  // public method
  // return: String
  // overriding toString method
  public String toString() {
    return "-------------------------------------------------------------------------------\n"
          + "Business ID: " + businessID + "\n"
          + "Business Name: " + businessName + "\n"
          + "Business Address: " + businessAddress + "\n"
          //+ "Reviews: " + reviews + "\n"
          + "Character Count: " + reviewCharCount;
  }

  // public method
  // parameter: Business; return: int
  // overriding compareTo methods from Comparable<Business>
  // sort Businesses in ascending order according to the number of characters in their reviews
  @Override
  public int compareTo(Business b){
    if(reviewCharCount == b.reviewCharCount){
      return 0;
    }else if(reviewCharCount > b.reviewCharCount){
      return -1;
    }else{
      return 1;
    }
  }
}