package assessment;

import java.io.FileNotFoundException;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.Text;
import org.xml.sax.SAXException;

import assessment.exception.TransformationException;

public abstract class BaseTransformer implements Transformer{
	
	protected final Integer orderOfTransformation;
	protected Integer actualOrderOfTransformation;
	private final Element transformerElementTag;
	protected final boolean transformerIsOn;
	private final String configFileLocation;
	private final TransformersTagNames transformerTag;
	
	public BaseTransformer(String configFile) {
		configFileLocation = configFile;
		transformerTag = getTransformTag();
		transformerElementTag = getTransformerTagElement();
		orderOfTransformation = getOrderOfTransformation();
		transformerIsOn = getTranformerState();
		actualOrderOfTransformation = 0;
	}
	

	private boolean getTranformerState() {
		Node text = transformerElementTag.getChildNodes().item(0);
		
		if(text == null)
			return false;
			
		if(text.getNodeType() != Node.TEXT_NODE)
			return false;
		
		Text fullText = (Text) text;
		
		return fullText.getWholeText().equals(TransformersTagNames.ON.getTagName());
	}

	private Element getTransformerTagElement() {
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();

		try {
			DocumentBuilder db;
			Document doc;
			Node node;

			db = dbf.newDocumentBuilder();
			doc = db.parse(configFileLocation);
			node = doc.getElementsByTagName(transformerTag.getTagName()).item(0);

			if (node != null)
				if (node.getNodeType() == Node.ELEMENT_NODE)
					return (Element) node;

			throw new TransformationException("Error parsing configuration file");

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		return null;
	}

	private Integer getOrderOfTransformation() {

		if(transformerElementTag == null)
			throw new TransformationException("Error parsing configuration file");
		
		String order = transformerElementTag
				.getAttribute(TransformersTagNames.ORDER.getTagName());
		try {

			return Integer.parseInt(order);

		} catch (NumberFormatException e) {
			throw new TransformationException("Error parsing configuration file");
		}

	}
	
	@Override
	public void setActualOrderOfTransformation(Integer new_order) {
		actualOrderOfTransformation = new_order;
	}

	public abstract String transform(String toBeTransformed);
	
	protected abstract TransformersTagNames getTransformTag();

}
