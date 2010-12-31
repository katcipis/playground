package br.com.oncast.tests;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import br.com.oncast.Book;

public class BookTest {

	private Book deitelBook;
	private String deitelBookAuthor;
	private String deitelBookTitle;
	private Integer deitelBookEditionYear;
	
	@Before
	public void setUp(){
		deitelBookTitle       = "Java how to program";
		deitelBookAuthor      = "Deitel & Deitel";
		deitelBookEditionYear = 2007;
		deitelBook            = new Book(deitelBookTitle, deitelBookAuthor, deitelBookEditionYear);
	}

	
	@Test
	public void knowsItsTitle(){
		
		assertEquals(deitelBookTitle, deitelBook.getTitle());
	}
	
	@Test
	public void knowsItsAuthor(){
		
		assertEquals(deitelBookAuthor, deitelBook.getAuthor());
	}
	
	@Test
	public void knowsItsEditionYear(){
		
		assertEquals(deitelBookEditionYear, deitelBook.getEditionYear());
	}
	
	@Test
	public void ifTwoBooksHaveDifferentAuthorsThenTheyAreNotEqual(){
		
		Book otherBook = new Book(deitelBook.getTitle(), deitelBook.getAuthor() + "dif", deitelBook.getEditionYear());
		assertFalse(otherBook.equals(deitelBook));
	}
	
	@Test
	public void ifTwoBooksHaveDifferentTitleThenTheyAreNotEqual(){
		
		Book otherBook = new Book(deitelBook.getTitle() + "dif", deitelBook.getAuthor(), deitelBook.getEditionYear());
		assertFalse(otherBook.equals(deitelBook));
	}
	
	@Test
	public void ifTwoBooksHaveDifferentEditionYearThenTheyAreNotEqual(){
		
		Book otherBook = new Book(deitelBook.getTitle(), deitelBook.getAuthor(), deitelBook.getEditionYear() + 1);
		assertFalse(otherBook.equals(deitelBook));
	}
	
	@Test
	public void ifTwoBooksHaveTheSameTitleAuthorAndEditionYearThenTheyAreEqual(){
		
		Book otherBook = new Book(deitelBook.getTitle(), deitelBook.getAuthor(), deitelBook.getEditionYear());
		assertEquals(otherBook, deitelBook);
	}
}
