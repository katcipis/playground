package br.com.oncast;

/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */
public class Book {

	private String title;
	private String author;
	private Integer editionYear;
	
	/**
	 * Constructs a book with the given parameters.
	 *
	 * @param title Book's title.
	 * @param author Book's author.
	 * @param editionYear Book's edition year.
	 */
	public Book(String title, String author, Integer editionYear){
		this.title       = title;
		this.author      = author;
		this.editionYear = editionYear;
	}

	/**
	 * Get the title of the Book.
	 *
	 * @return Book's title.
	 */
	public String getTitle() {
		return this.title;
	}
	
	/**
	 * Get the author of the Book.
	 *
	 * @return Book's author.
	 */
	public String getAuthor() {
		return this.author;
	}
	
	/**
	 * Get the edition year of the Book.
	 *
	 * @return Book's edition year.
	 */
	public Integer getEditionYear() {
		return this.editionYear;
	}
	
	@Override
	public String toString(){
		return this.title + "\n" +
		       this.author + "\n" + 
		       this.editionYear.toString();
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
		
		return (this.author.equals(other.author)) &&
		       (this.title.equals(other.title)) &&
		       (this.editionYear.equals(other.editionYear));
	}
}
