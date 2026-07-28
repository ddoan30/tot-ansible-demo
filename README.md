<body>
  <h2>
  Event-Driven Ansible (EDA) Quick Demo 
  </h2>

  <h4>
    The Set-Up Consists of Three Parts
  </h4>
<ol start=1 >
  <li> <b><i>Target node with Arduino IDE compatibility</b></i> </li>
  <li> <b><i>Single-node to host Ansible Automation Platform (AAP)</b></i> </li>
  <li> <b><i>Touch sensor and lightbulb configured with Arduino </b></i></li>
</ol>
<br>
<h4> Configuring #1 </h4>

I am using a RHEL 9.7 VM on my laptop running Fedora. Generally, you will just need at least 4GB of RAM and sufficient memory for Arduino IDE installation (~600MB but be generous).

<ol start=1>
  <li>Register your system: <code>subscription-manager register</code> and follow prompts</li>
  <li>Install Arduino IDE and give your user access to dialout group: </li>
  <ul>
    <li> <code>$ sudo flatpak remote-add --if-not-exists flathub https://flathub.org</code></li>
    <li> <code>$ sudo flatpak install flathub cc.arduino.IDE2</code></li>
    <li> <code>$ sudo flatpak run cc.arduino.IDE2</code> </li>
    <li> <code>$ sudo usermod -a -G dialout $USER</code></li>
  </ul>
</ol>
<br>

<h4> Configuring #2 </h4>

  Again, I am using a RHEL 9.7 VM on my local Fedora virt-manager, with 4 vCPUs and 19073 MiB memory. 4 CPUs, 16GB RAM, and at least 40GB in disk space is the minimum recommended baseline.  

<ol start=1>
  <li>Register your system: <code>$ subscription-manager register</code> and follow prompts</li>
  
  <li><a href="https://docs.redhat.com/en/documentation/red_hat_ansible_automation_platform/2.4/html/containerized_ansible_automation_platform_installation_guide/aap-containerized-installation#downloading-containerizzed-aap_aap-containerized-installation)">Install AAP 2.4+ containerized</a></li>
  <ul>
    <li>Feel free to reference <code>inventory-growth.ini</code> as needed. </li>
    <li>Hold onto </li>
  </ul>
  
  <li>Access your AAP Gateway Link (the link to your platform console) and open in a browser</li>
  
  <li>Add target node as a host in AAP Inventory</li>
  <ul>
    <li>Infrastructure > Inventories > Create inventory > Create your own inventory > </li>
    <li>Navigate to new inventory > Hosts > Create host > use FQDN of target host as Hostname </li>
    <li>Follow prompts and check that target node is listed in Hosts </li>
  </ul>
  
  <li>Create a project to sync with a Git(hub) repo</li>
  <ul>
    <li>Projects > Create project > Fill in form, selecting Default if applicable</li>
    <li>Source control type: Git</li>
    <li>Source control URL: 	&lt; link to your Git(hub) repo, forked from this one &gt;</li>
    <li>Create project</li>
    <img src="https://github.com/ddoan30/tot-ansible-demo/blob/main/extras/AAP_Projects.png" alt="Screenshot of Projects tab" width=70%>
  </ul>

  <li>Setting up Event-Driven Ansible (EDA)</li>
  <ul>
    <li>Create EDA project: Automation Decisions > Projects > Create project > complete form using your forked repo as the source control URL </li>
    <li>Create Red Hat Registry service account:</li>
    <ul>
      <li><a href="https://access.redhat.com/terms-based-registry/"> Use this link.</a></li>
      <li>It should give you a username and token; save both somewhere for the next step. </li>
    </ul>
    <li>Create container registry credential: Automation Decisions > Infrastructure > Credentials > Create credential</li>
    <ul>
      <li>Credential type: Container Registry</li>
      <li>Host: registry.redhat.io</li>
      <li>Username: XXXXXXXX|user (from previous step)</li>
      <li>Password/token: &lt;token from previous step&gt; </li>
    </ul>
    <li>Create EDA API credential: Automation Decisions > Infrastructure > Credentials > Create credential</li>
    <ul>
      <li>Credential type: Red Hat Ansible Automation Platform</li>
      <li>(Type Details) Red Hat Ansible Automation Platform: https://&lt;yourgatewayURL&gt;/api/controller</li>
    </ul>
    <li>Create Decision Environment: Automation Decisions > Decision Environments > Create decision environment</li>
    <ul>
      <li>Name: Default Decision Environment</li>
      <li>Complete form using an <a href="https://catalog.redhat.com/en/search?q=decision+environment&searchType=Containers"> appropriate Decision Environment image for your version.</a> </li>
      <li>Credential: &lt;name of credential you saved previously&gt; </li>
    </ul>
    <li>Generate EDA API credential: <a href="https://docs.redhat.com/en/documentation/red_hat_ansible_automation_platform/2.4/html/event-driven_ansible_controller_user_guide/eda-set-up-token"> Instructions</a></li>
    <li>Create Rulebook Activation: Automation Decisions > Rulebook Activations > Create rulebook activation</li>
    <ul>
      <li>Project: &lt;select the one you made earlier&gt;</li>
      <li>Rulebook: <code>tot-rulebook.yml</code></li>
      <li>Decision environment: Default Decision Environment</li>
      <li>Credential: &lt;enter the EDA API token from previous step&gt;</li>
    </ul>
      
  </ul>
</ol>

<h4> Configuring #3 </h4>

</body>
