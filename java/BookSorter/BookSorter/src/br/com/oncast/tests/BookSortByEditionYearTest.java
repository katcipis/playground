package br.com.oncast.tests;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import br.com.oncast.tests.BookSortOperationTest;
import br.com.oncast.Book;
import br.com.oncast.BookSortByEditionYear;
import br.com.oncast.BookSortOperation;

public class BookSortByEditionYearTest extends BookSortOperationTest {


	@Override
	protected BookSortOperation getAscendingOperation() {
		return new BookSortByEditionYear(BookSortOperation.Direction.ASCENDING);
	}



	@Override
	protected BookSortOperation getDescendingOperation() {
		return new BookSortByEditionYear(BookSortOperation.Direction.DESCENDING);
	}


	@Override
	protected Set<Book> getUnordered() {
		List<Book> unordered = new ArrayList<Book>();

        unordered.add(new Book("Patterns of enterprise", 
                "Martin Fowler", 2010));
        
        unordered.add(new Book("Java how to program", 
                "Deidel & Deidel", 1994));

        unordered.add(new Book("Design Patterns", 
                "Elishabeth Freeman", 2004));
        
        return new HashSet<Book>(unordered);
	}


	@Override
	protected List<Book> getAscending() {
		List<Book> ascendingByTitle = new ArrayList<Book>();
		
		ascendingByTitle.add(new Book("Java how to program", 
                "Deidel & Deidel", 1994));
		
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
                "Deidel & Deidel", 1994));
        
        return descendingByTitle;
	}

}
