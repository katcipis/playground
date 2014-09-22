package katcipis
import org.junit.Test
import org.junit.Assert._
import org.junit.Before

class JsonHalRegexTest {
  
  var jsonParser : JsonHalParser = _
  
  @Before def setUp {
	  jsonParser = new JsonHalParser("""{"stateData":"ok","_links":{"self":{"href":"/selfUri"},"audio":{"href":"/audioUri"},"waveform":{"href":"/waveformUri"}}}""");
  }
  
  @Test def givenAJsonHalCanExtractTheSelfRelationsUri {
	  assertEquals("/selfUri" , jsonParser.getRelationUri("self"))
  }
  
  @Test def givenAJsonHalCanExtractTheAudioRelationsUri {
	  assertEquals("/audioUri" , jsonParser.getRelationUri("audio"))
  }
  
  @Test def givenAJsonHalCanExtractTheWaveformRelationsUri {
	  assertEquals("/waveformUri" , jsonParser.getRelationUri("waveform"))
  }
}