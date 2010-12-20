package gui;

import java.awt.Desktop;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import org.xml.sax.SAXException;

import uploading.GadgetUploader;

/*
 * GetAutenticationGui.java
 *
 * Created on 10 de Janeiro de 2008, 14:23
 */



/**
 * @author  katcipis
 */
public class GetAuthenticationGui extends javax.swing.JFrame {
    
    /**
	 * 
	 */
	private static final long serialVersionUID = -5661056077167249648L;
	/** Creates new form GetAutenticationGui */
    public GetAuthenticationGui() {
        initComponents();
    }
    
  
    private void initComponents() {

    	okButton = new javax.swing.JButton();
        pressOkLabel = new javax.swing.JLabel();
        pressOk2label = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Authenticate First Please");

        okButton.setText("Ok");
        okButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                okButtonActionPerformed(evt);
            }
        });

        pressOkLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        pressOkLabel.setText("Your browser will open a Flickr authentication page. After you ");

        pressOk2label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        pressOk2label.setText("authenticate press ok to upload");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(pressOkLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 356, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(78, Short.MAX_VALUE)
                .addComponent(pressOk2label, javax.swing.GroupLayout.PREFERRED_SIZE, 211, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(87, 87, 87))
            .addGroup(layout.createSequentialGroup()
                .addGap(159, 159, 159)
                .addComponent(okButton)
                .addContainerGap(172, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(pressOkLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(pressOk2label)
                .addGap(18, 18, 18)
                .addComponent(okButton)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
        
        this.openBrowserToAuthenticate();
    }
    
    private void okButtonActionPerformed(java.awt.event.ActionEvent evt) {
        System.out.println("should do something :P");
    }
    
    
    public static void openAuthenticationGui() {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new GetAuthenticationGui().setVisible(true);
            }
        });
    }
    
    private void openBrowserToAuthenticate() {
		Desktop desktop = null;
	
		if (!Desktop.isDesktopSupported())
			throw new IllegalStateException("Desktop resources not supported!");

		desktop = Desktop.getDesktop();
		
		if (!desktop.isSupported(Desktop.Action.BROWSE))
			throw new IllegalStateException("No default browser set!");

		
		URI uri = null;
		try {
			uri = new URI(GadgetUploader.getUploader().getAuthenticationUrl().toExternalForm());
		} catch (URISyntaxException e1) {
			e1.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		}

		try {
			desktop.browse(uri);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
    

    private javax.swing.JLabel pressOk2label;
    private javax.swing.JButton okButton;
    private javax.swing.JLabel pressOkLabel;
    
}
