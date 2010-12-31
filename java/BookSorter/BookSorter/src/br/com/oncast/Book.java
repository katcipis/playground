/**
 * 
 */
package br.com.oncast;

/**
 * @author Katcipis
 *
 */
public class Book {

	private String title;
	private String author;
	private Integer editionYear;
	
	public Book(String title, String author, Integer editionYear){
		this.title       = title;
		this.author      = author;
		this.editionYear = editionYear;
	}

	public String getTitle() {
		return this.title;
	}
	
	public String getAuthor() {
		return this.author;
	}
	
	public Integer getEditionYear() {
		return this.editionYear;
	}
	
	@Override
	public int hashCode(){
		String hashGen = this.title + this.author + this.editionYear.toString();
		return  hashGen.hashCode();
	}
	
	@Override
	public boolean equals(Object o){
		if (this == o) {
			return true;
		}
		
		if (getClass() != o.getClass()){
			return false;
		}
		
		Book other = (Book) o;
		
		return (this.author == other.author) &&
		       (this.title == other.title) &&
		       (this.editionYear == other.editionYear);
	}
}
