package br.com.oncast.tests;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

import br.com.oncast.tests.BookSortOperationTest;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import br.com.oncast.Book;
import br.com.oncast.BookSortByTitle;
import br.com.oncast.BookSortOperation;

public class BookSortByTitleTest extends BookSortOperationTest {

	private List<Book> ascendingByTitle;
	private List<Book> descendingByTitle;
	private Set<Book> unordered;
	
	@Before
	public void setUp(){
		ascendingByTitle = new ArrayList<Book>();
		descendingByTitle = new ArrayList<Book>();
		unordered         = new TreeSet<Book>();
	}
	
	@Test
	public void canSortBooksOnAscendingOrder() {
		// TODO Auto-generated method stub
		
	}

	@Test
	public void canSortBooksOnDescendingOrder() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public BookSortOperation getOperation() {
		return new BookSortByTitle(BookSortOperation.Direction.ASCENDING);
	}

}
