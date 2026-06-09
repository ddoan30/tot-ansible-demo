<body>
  <h2>
  Event-Driven Ansible (EDA) Quick Demo 
  </h2>

  <h4>
    The Set-Up
  </h4>
<ol start=1 >
  <li> Target node with Arduino IDE compatibility </li>
  <li> Single-node to host Ansible Automation Platform (AAP) </li>
  <li> Touch sensor and lightbulb configured with Arduino </li>
</ol>
<br>
<h4> Configuring #1 </h4>

<h4> Configuring #2 </h4>

  I am using a RHEL 9.7 VM on my local Fedora virt-manager, with 4 vCPUs and 19073 MiB memory. 4 CPUs, 16GB RAM, and at least 40GB in disk space is the minimum recommended baseline.  

<ol start=1>
  <li><a href="https://docs.redhat.com/en/documentation/red_hat_ansible_automation_platform/2.4/html/containerized_ansible_automation_platform_installation_guide/aap-containerized-installation#downloading-containerizzed-aap_aap-containerized-installation)">Install AAP containerized</a></li>
  <ul>
    <li>Feel free to reference <code>inventory-growth.ini</code> as needed. </li>
  </ul>
  <li>Access your AAP Gateway Link (the link to your platform console)</li>
  <ul>
    <li>Infrastructure > Inventories > Create inventory > Create your own inventory > </li>
    <li>Navigate to new inventory > Hosts > Create host > use FQDN of target host as Hostname</li>
  </ul>
  
</ol>

</body>
