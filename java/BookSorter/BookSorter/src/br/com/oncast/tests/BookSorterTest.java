package br.com.oncast.tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import br.com.oncast.Book;
import br.com.oncast.BookSortByAuthor;
import br.com.oncast.BookSortByEditionYear;
import br.com.oncast.BookSortByTitle;
import br.com.oncast.BookSortOperation;
import br.com.oncast.BookSorter;
import br.com.oncast.OrderingException;

public class BookSorterTest {

	private List<Book> unorderedBooks;
	
	@Before
	public void ListUp(){
		unorderedBooks = new ArrayList<Book>();
		unorderedBooks.add(new Book("Java How to Program", "Deitel & Deitel", 2007));
		unorderedBooks.add(new Book("Patterns of Enterprise Application Architecture", "Martin Fowler", 2002));
		unorderedBooks.add(new Book("Head First Design Patterns", "Elisabeth Freeman", 2004));
		unorderedBooks.add(new Book("Internet & World Wide Web: How to Program", "Deitel & Deitel", 2007));
	}

	
	//@Test
	public void canOrderByTitleOnAscendingDirection(){
		List<Book> orderedBooks            = new ArrayList<Book>();
		List<BookSortOperation> operations = new ArrayList<BookSortOperation>();
		BookSorter sorter                  = new BookSorter(operations);
		List<Book> result;
		
		operations.add(new BookSortByTitle(BookSortOperation.Direction.ASCENDING));
		
		orderedBooks.add(new Book("Head First Design Patterns", "Elisabeth Freeman", 2004));
		orderedBooks.add(new Book("Internet & World Wide Web: How to Program", "Deitel & Deitel", 2007));
		orderedBooks.add(new Book("Java How to Program", "Deitel & Deitel", 2007));
		orderedBooks.add(new Book("Patterns of Enterprise Application Architecture", "Martin Fowler", 2002));
		
		result = sorter.sort(new ArrayList<Book>(unorderedBooks));
		
		Iterator<Book> iter = result.iterator();
		int i               = 0;
		
		while(iter.hasNext()) {
			Book a = iter.next();
			Book b = orderedBooks.get(i);
			
			assertEquals(a,b);
			i++;
		}
	}
	
	@Test
	public void canOrderByAuthorOnAscendingDirectionAndTitleOnDescendingDirection(){
		List<Book> orderedBooks            = new ArrayList<Book>();
		List<BookSortOperation> operations = new ArrayList<BookSortOperation>();
		BookSorter sorter                  = new BookSorter(operations);
		List<Book> result;
		
		operations.add(new BookSortByAuthor(BookSortOperation.Direction.ASCENDING));
		operations.add(new BookSortByTitle(BookSortOperation.Direction.DESCENDING));
		
		orderedBooks.add(new Book("Java How to Program", "Deitel & Deitel", 2007));
		orderedBooks.add(new Book("Internet & World Wide Web: How to Program", "Deitel & Deitel", 2007));
		orderedBooks.add(new Book("Head First Design Patterns", "Elisabeth Freeman", 2004));
		orderedBooks.add(new Book("Patterns of Enterprise Application Architecture", "Martin Fowler", 2002));
		
		result = sorter.sort(new ArrayList<Book>(unorderedBooks));
		
		Iterator<Book> iter = result.iterator();
		int i               = 0;
		
		System.out.println("<<<<<<<<<<< TEST START >>>>>>>>>>>>>");
		
		while(iter.hasNext()) {
			Book a = iter.next();
			Book b = orderedBooks.get(i);
			
			assertEquals(a,b);
			
			System.out.println(a);
				
			i++;
		}
		
		System.out.println("<<<<<<<<<<<< TEST END >>>>>>>>>>>");
	}
	
	@Test
	public void canOrderByEditionOnDescendingDirectionAndAuthorOnDescendingDirectionAndTitleOnAscendingDirection(){
		List<Book> orderedBooks            = new ArrayList<Book>();
		List<BookSortOperation> operations = new ArrayList<BookSortOperation>();
		BookSorter sorter                  = new BookSorter(operations);
		List<Book> result;
		
		operations.add(new BookSortByEditionYear(BookSortOperation.Direction.DESCENDING));
		operations.add(new BookSortByAuthor(BookSortOperation.Direction.DESCENDING));
		operations.add(new BookSortByTitle(BookSortOperation.Direction.ASCENDING));
		
		orderedBooks.add(new Book("Internet & World Wide Web: How to Program", "Deitel & Deitel", 2007));
		orderedBooks.add(new Book("Java How to Program", "Deitel & Deitel", 2007));
		orderedBooks.add(new Book("Head First Design Patterns", "Elisabeth Freeman", 2004));
		orderedBooks.add(new Book("Patterns of Enterprise Application Architecture", "Martin Fowler", 2002));
		
		result = sorter.sort(new ArrayList<Book>(unorderedBooks));
		
		Iterator<Book> iter = result.iterator();
		int i               = 0;
		
		while(iter.hasNext()) {
			Book a = iter.next();
			Book b = orderedBooks.get(i);
			
			assertEquals(a,b);
			i++;
		}
	}
	
	@Test
	public void ifAnEmptyListIsGivenReturnsAEmptyList() {
		List<BookSortOperation> operations = new ArrayList<BookSortOperation>();
		BookSorter sorter                  = new BookSorter(operations);
		List<Book> empty = new ArrayList<Book>();
		
		assertEquals(new ArrayList<Book>(), sorter.sort(empty));
	}
	
	@Test(expected = OrderingException.class)
	public void ifTheGivenListIsNullThrowsAOrderingException(){
		List<BookSortOperation> operations = new ArrayList<BookSortOperation>();
		BookSorter sorter                  = new BookSorter(operations);
		
        sorter.sort(null);
	}
}
