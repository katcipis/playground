package assessment;

import assessment.exception.TransformationException;
import assessment.TransformersTagNames;

public class UpperCaseTransformer extends BaseTransformer {


	public UpperCaseTransformer(String configFile) {
		super(configFile);
	}

	@Override
	public String transform(String toBeTransformed) {

		if (toBeTransformed == null)
			throw new TransformationException("Invalid string");

		if (!orderOfTransformation.equals(actualOrderOfTransformation) || !transformerIsOn)
			return toBeTransformed;

		String upperCased = toBeTransformed.toUpperCase();
		return upperCased;
	}

	@Override
	protected TransformersTagNames getTransformTag() {
		
		return TransformersTagNames.UPPER_CASE;
	}


}
