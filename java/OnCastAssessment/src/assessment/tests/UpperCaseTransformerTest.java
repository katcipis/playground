package assessment.tests;

import assessment.ConfigFile;
import assessment.UpperCaseTransformer;

public class UpperCaseTransformerTest extends BaseTransformerTest{


	protected void setStringsToPerformTest() {
		beforeTransformationString = "Test";
		afterTransformationString = "TEST";
	}

	protected void setActualOrdersToTheTransformers() {
		transformerWithRightOrder.setActualOrderOfTransformation(1);
		transformerConfiguredToOffWithRightOrder.setActualOrderOfTransformation(1);
		transformerWithWrongOrder.setActualOrderOfTransformation(2);
	}

	protected UpperCaseTransformer getTransformerConfiguredToOffWithRightOrder() {
		return new UpperCaseTransformer(ConfigFile.NO_UPPER_LOCATION.getFileLocation());
	}

	protected UpperCaseTransformer getTransformerWithRightOrder() {
		return new UpperCaseTransformer(ConfigFile.FULL_LOCATION.getFileLocation());
	}
	
	
	
}
