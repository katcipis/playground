package assessment.tests;

import assessment.BlankSpaceTransformer;
import assessment.ConfigFile;
import assessment.Transformer;

public class BlankSpaceTransformerTest extends BaseTransformerTest{


	protected void setStringsToPerformTest() {
		beforeTransformationString = "	Te s  t  ";
		afterTransformationString = "Test";
	}

	protected void setActualOrdersToTheTransformers() {
		transformerWithRightOrder.setActualOrderOfTransformation(2);
		transformerConfiguredToOffWithRightOrder.setActualOrderOfTransformation(2);
		transformerWithWrongOrder.setActualOrderOfTransformation(1);
	}

	protected Transformer getTransformerConfiguredToOffWithRightOrder() {
		return new BlankSpaceTransformer(ConfigFile.NO_SUPRESS_BLANK_LOCATION.getFileLocation());
	}

	protected Transformer getTransformerWithRightOrder() {
		return new BlankSpaceTransformer(ConfigFile.FULL_LOCATION.getFileLocation());
	}
	
	
	
}
