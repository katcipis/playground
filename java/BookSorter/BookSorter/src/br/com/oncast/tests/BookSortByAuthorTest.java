package br.com.oncast.tests;
import java.util.ArrayList;
import java.util.List;
import br.com.oncast.tests.BookSortOperationTest;
import br.com.oncast.Book;
import br.com.oncast.BookSortByAuthor;
import br.com.oncast.BookSortOperation;

public class BookSortByAuthorTest extends BookSortOperationTest {


	@Override
	protected BookSortOperation getAscendingOperation() {
		return new BookSortByAuthor(BookSortOperation.Direction.ASCENDING);
	}



	@Override
	protected BookSortOperation getDescendingOperation() {
		return new BookSortByAuthor(BookSortOperation.Direction.DESCENDING);
	}


	@Override
	protected List<Book> getUnordered() {
		List<Book> unordered = new ArrayList<Book>();
		
		unordered.add(new Book("Java how to program", 
                "Deidel & Deidel", 2007));

        unordered.add(new Book("Patterns of enterprise", 
                "Martin Fowler", 2010));

        unordered.add(new Book("Design Patterns", 
                "Elishabeth Freeman", 2004));
        
        return new ArrayList<Book>(unordered);
	}


	@Override
	protected List<Book> getAscending() {
		List<Book> ascendingByTitle = new ArrayList<Book>();

		ascendingByTitle.add(new Book("Java how to program", 
                "Deidel & Deidel", 2007));
		
		ascendingByTitle.add(new Book("Design Patterns", 
                "Elishabeth Freeman", 2004));

        ascendingByTitle.add(new Book("Patterns of enterprise", 
                "Martin Fowler", 2010));
        
        return ascendingByTitle;
	}


	@Override
	protected List<Book> getDescending() {
		List<Book> descendingByTitle = new ArrayList<Book>();
		
		descendingByTitle.add(new Book("Patterns of enterprise", 
                "Martin Fowler", 2010));
		
		descendingByTitle.add(new Book("Design Patterns", 
                "Elishabeth Freeman", 2004));

        descendingByTitle.add(new Book("Java how to program", 
                "Deidel & Deidel", 2007));
        
        return descendingByTitle;
	}

}
