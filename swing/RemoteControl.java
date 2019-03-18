import java.awt.event.ActionEvent;

import javax.swing.*;

public class RemoteControl extends JFrame{
	
	private static final long serialVersionUID = 1L;
	private JTextArea textArea;
	private JTextField textField,textField2;
	private JButton close;
	private JButton play;
	private JButton searchMedia;
	private JButton searchGroup;
	private JPanel playPanel;
	private JPanel searchMediaPanel;
	private JPanel searchGroupPanel;
	private JScrollPane scrollPane;
	
	private String fileName = "";
	private String groupName = "";
	private Client client;
	private String request, response;
	
	public static void main(String[] args) {
		new RemoteControl();
	}
	
	public RemoteControl() {
		client = null;

		try {
			client = new Client("localhost", 3331);
		}
		catch (Exception e) {
			System.err.println("Client: Couldn't connect to "+"localhost"+":"+3331);
			System.exit(1);
		}

		System.out.println("Client connected to "+"localhost"+":"+3331);
		
		this.setTitle("Client UI");
		this.setSize(300,300);
		this.setLocationRelativeTo(null);
		
		textArea = new JTextArea(30, 40);
		textArea.setText("By defaut, this database contains: \nPhoto: {Monkey,Bamboo}; Video: {Reflet}; Group: {Animal,Plant} \n");
		textArea.append("---------------------------------------------------\n");
		textField = new JTextField(20);
		textField2 = new JTextField(20);
		close = new JButton("Close");
		play= new JButton("Play Media");
		searchMedia= new JButton("Search Media");
		searchGroup= new JButton("Search Group");
		
		playPanel = new JPanel();
		playPanel.add(new JLabel("Filename"));
		playPanel.add(textField);
		playPanel.add(play);
		
		searchMediaPanel = new JPanel();
		searchMediaPanel.add(searchMedia);
		
		searchGroupPanel = new JPanel();
		searchGroupPanel.add(new JLabel("Groupname"));
		searchGroupPanel.add(textField2);
		searchGroupPanel.add(searchGroup);;
		
		textArea.setLineWrap(true); 
		scrollPane = new JScrollPane(
                textArea,
                ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
                ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER
        );
		
		
        JMenuBar menuBar = new JMenuBar();
        JMenu myMenu = new JMenu("Menu");
        menuBar.add(myMenu);
        JMenuItem playMenuItem = new JMenuItem("Play Media");
        JMenuItem searchMediaMenuItem = new JMenuItem("Search Media");
        JMenuItem searchGroupMenuItem = new JMenuItem("Search Group");
        JMenuItem closeMenuItem = new JMenuItem("Close");
        myMenu.add(playMenuItem);
        myMenu.add(searchMediaMenuItem);
        myMenu.add(searchGroupMenuItem);
        myMenu.addSeparator();       
        myMenu.add(closeMenuItem);

        JToolBar toolBar = new JToolBar("Tool");
        toolBar.add(play);
        toolBar.add(searchMedia);
        toolBar.add(searchGroup);
        toolBar.add(close);

		Box vBox = Box.createVerticalBox();
		vBox.add(toolBar);
		vBox.add(playPanel);
		vBox.add(searchMediaPanel);
		vBox.add(searchGroupPanel);
        vBox.add(scrollPane);

        this.setContentPane(vBox);
        this.setJMenuBar (menuBar);
        
        class AbstractEvent extends AbstractAction{
        	/**
			 * 
			 */
			private static final long serialVersionUID = 1L;
			//private static final long serialVersionUID = 1L;
        	AbstractEvent(){
        	}
        	public void actionPerformed(ActionEvent e){
        		if (e.getActionCommand()=="Play Media"){
        			fileName = textField.getText();
        			if(fileName.isEmpty()) {
        				JOptionPane.showMessageDialog(null, "Please input file name!", "Warning", JOptionPane.WARNING_MESSAGE);
        			}
        			else {
        				request = "play " + fileName;
        				response = client.send(request);
        				textArea.append("Response: " + response + '\n'+ '\n');
        			}
        		}else if (e.getActionCommand()=="Close"){
        			System.exit(0);
        		}else if (e.getActionCommand()=="Search Media"){
        			fileName = textField.getText();
        			if(fileName.isEmpty()) {
        				JOptionPane.showMessageDialog(null, "Please input file name!", "Warning", JOptionPane.WARNING_MESSAGE);
        			}
        			else {
        				request = "findM " + fileName;
        				response = client.send(request);
        				textArea.append("Response: " + response + '\n' + '\n');
        			}
        		}else if (e.getActionCommand()=="Search Group"){
        			groupName = textField2.getText();
        			if(groupName.isEmpty()) {
        				JOptionPane.showMessageDialog(null, "Please input group name!", "Warning", JOptionPane.WARNING_MESSAGE);
        			}
        			else {
        				request = "findG " + groupName;
        				response = client.send(request);
        				textArea.append("Response: " + response + '\n'+ '\n');
        			}
        		}
        	}
        }

        final Action ButtonEvent=new AbstractEvent();
        play.addActionListener(ButtonEvent);
        searchMedia.addActionListener(ButtonEvent);
        searchGroup.addActionListener(ButtonEvent); 
        close.addActionListener(ButtonEvent);
		
        final Action MenuEvent=new AbstractEvent();
        playMenuItem.addActionListener(MenuEvent);
        searchMediaMenuItem.addActionListener(MenuEvent);    
        searchGroupMenuItem.addActionListener(MenuEvent); 
        closeMenuItem.addActionListener(MenuEvent);
        
		
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);
		System.setProperty ("apple.laf.useScreenMenuBar", "true");
	}

}


