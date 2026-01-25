<div align=center>
	<p>
	<i>
	This project has been created as part of the 42 curriculum by
	<b>pcordero</b>
	</i>
	</p>
	<h1>Born2BeRoot</h1>
</div>

## Description

**Born2BeRoot** is a 42 Cursus curriculum project designed to introduce students to Linux system administration, virtualization, and cybersecurity best practices.

The project involves creating and configuring a virtual machine from scratch, following a strict set of rules related to user management, system services, access policies and security. Through this project, students acquire fundamental knowledge on how a Linux operating system works at a low level and how to secure a basic server environment.

## Technical Approach

For the VM environment we decided to use **VirtualBox** for its extended compatibility and the support of this tool inside the 42 campus.

For this project we choose **Debian** as our SO, due to its more extensive documentation and easier approach for a newcomer.

In the same line we choose **AppArmor** as seem simpler to implement and it comes already as part of our Debian system. 

And we decided to go with **UFW (Uncomplicated Firewall)** for its simplicity and ease of use being this our first approach to a firewall configuration. 

<div align=center>

<h3>Debian vs Rocky Linux</h3>

| Debian 				| Rocky Linux 				|
|-						|-							|
| Comunity oriented. 	| Bussiness oriented. 		|
| More flexible. 		| More strict. 				|
| Well documented. 		| Red Hat compatibility. 	|

<br>

<h3>AppArmor vs SELinux</h3>

| AppArmor 				| SELinux 				|
|-						|-						|
| Easier to configure. 	| Harder to configure.	|
| Path-based. 			| Tag-based. 			|
| Begginer friendly. 	| Steep learning curve.	|

<br>

<h3>UFW vs Firewalld</h3>

| UFW 						| Firewalld 					|
|-							|-								|
| Best for beginners. 		| More dynamic & complex rules. |
| Ideal for simpler setups. | Ideal for bigger enviroments. |
| Less flexible. 			| More complex. 				|

<br>

</div>

## Design Approach

- **Partitioning**: Use of LVM for greater flexibility in storage management.

- **Security Policies:**
  - Strong passwords.
  - Periodic password changes.
  - Restricted remote access to root.

- **User Management:**
  - Primary user without direct root privileges.
  - Use of `sudo`.

- **Installed Services:**
  - SSH (configured on a custom port).
  - UFW as a firewall.
  - Cron for scheduled tasks.

- **Monitoring:**
  - Monitoring script executed periodically, displaying system information.

## Cheatsheet

- **User & Group Management:**
  - Add a new user: `sudo adduser <username>`
  - Add a new group: `sudo addgroup <groupname>`
  - Add user to group `sudo adduser <username> <groupname>`
  - Check groups `getent group <groupname>`
  - Change Hostname: `sudo hostnamectl set-hostname <new_name>` & edit `/etc/hosts`
  - Reboot System: `sudo reboot`

- **Services Commands:**
  - Apparmor status: `sudo apparmor_status` `aa-status`
  - SSH status: `sudo service ssh status`
  - SSH restart: `sudo service ssh restart`
  - UFW allow port: `sudo ufw allow <port_number>`
  - UFW status: `sudo ufw status`

- **Important Folders:**
  - SSH: `/etc/ssh/sshd_config` `/etc/ssh/sshd_config`
  - sudo: `/etc/sudoers.d/sudo_config`
  - PCR (Password Complexity Rules): `/etc/pam.d/common-password`
  - Crontab: `sudo crontab -u <username> -e`
