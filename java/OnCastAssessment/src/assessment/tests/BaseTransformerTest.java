package assessment.tests;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;

import org.junit.Before;
import org.junit.Test;

import assessment.ConfigFile;
import assessment.Transformer;
import assessment.UpperCaseTransformer;
import assessment.exception.TransformationException;

public abstract class BaseTransformerTest {

	protected String beforeTransformationString;
	protected String afterTransformationString;
	private String nullString;
	protected Transformer transformerWithRightOrder;
	protected Transformer transformerWithWrongOrder;
	protected Transformer transformerConfiguredToOffWithRightOrder;
	
	@Before
	public void setUp(){
		setStringsToPerformTest();
		
		transformerWithRightOrder = getTransformerWithRightOrder();
		transformerWithWrongOrder = getTransformerWithRightOrder();
		transformerConfiguredToOffWithRightOrder = getTransformerConfiguredToOffWithRightOrder();
		
		setActualOrdersToTheTransformers();
	}

	protected abstract Transformer getTransformerWithRightOrder();

	protected abstract Transformer getTransformerConfiguredToOffWithRightOrder();

	protected abstract void setActualOrdersToTheTransformers();

	protected abstract void setStringsToPerformTest();
	
	
	@Test
	public void afterTransformationWillBeTransformedAccordingToExpected(){
		assertEquals(afterTransformationString, transformerWithRightOrder.transform(beforeTransformationString));
	}
	
	@Test
	public void ifItsAlreadyTransformedWillRemainTransformed(){
		assertEquals(afterTransformationString, transformerWithRightOrder.transform(afterTransformationString));
	}
	
	@Test
	public void willTransformTheStringOnlyIfTheCorrectOrderHasBeenSet(){
		assertEquals(afterTransformationString, transformerWithRightOrder.transform(beforeTransformationString));
		assertFalse(afterTransformationString.equals(transformerWithWrongOrder.transform(beforeTransformationString)));
	}
	
	@Test
	public void willTransformTheStringOnlyIfTheTransfomerIsConfiguredToBeOn(){
		assertEquals(afterTransformationString, transformerWithRightOrder.transform(beforeTransformationString));
		assertFalse(afterTransformationString.equals(transformerConfiguredToOffWithRightOrder.transform(beforeTransformationString)));
	}
	
	@Test(expected = TransformationException.class)
	public void ifANullStringIsPassedWillThrowATransformationException(){
		transformerWithRightOrder.transform(nullString);
	}
	
	@Test(expected = TransformationException.class)
	public void ifTheConfigurationFileIsNotFoundThrowsATransformationException(){
		new UpperCaseTransformer("invalid");
	}
	
	@Test(expected = TransformationException.class)
	public void ifTheConfigurationFileIsInvalidThrowsATransformationException(){
		new UpperCaseTransformer(ConfigFile.INVALID_LOCATION.getFileLocation());
	}
}
