package assessment;

import java.util.HashSet;
import java.util.Set;

import assessment.exception.TransformationException;

public class BlankSpaceTransformer extends BaseTransformer{
	
	private final Set<String> toBeRemoved;
	
	public BlankSpaceTransformer(String configFile) {
		super(configFile);
		toBeRemoved = new HashSet<String>();
		toBeRemoved.add("\t");
		toBeRemoved.add("\r");
		toBeRemoved.add("\n");
		toBeRemoved.add(" ");
	}

	@Override
	public String transform(String toBeTransformed) {

		if (toBeTransformed == null)
			throw new TransformationException("Invalid string");

		if (!orderOfTransformation.equals(actualOrderOfTransformation) || !transformerIsOn)
			return toBeTransformed;

		String withoutSpaces = toBeTransformed.trim();
		
		for(String str : toBeRemoved)
			withoutSpaces = withoutSpaces.replaceAll(str, "");

		return withoutSpaces;
	}

	@Override
	protected TransformersTagNames getTransformTag() {
		
		return TransformersTagNames.BLANK_SPACES;
	}
}
