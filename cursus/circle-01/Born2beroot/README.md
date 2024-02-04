# Born2beRoot

This document is a System Administration related exercise.

## Introduction

This project aims to introduce you to the wonderful world of virtualization.

You will create your first machine in `VirtualBox` (or `UTM` if you can't use `VirtualBox`)
under specific instructions.
Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules.

## General Guidelines

- The use of `VirtualBox` (or `UTM` if you can't use `VirtualBox`) is mandatory.
- You only have to turn in a `signature.txt` file at the root of your repository.
You must paste in it the signature of your machine's virtual disk.

## Mandatory part

This project consists of having you set up your first server by following specific rules.

> ⚠️ Since it is a matter of setting up a server, you will install the minimum of services.
> For this reason, a graphical interface is of no use here.
> It is therefore forbidden to install X.org or any other equivalent graphics server.
> Otherwise, your grade will be 0.

You must choose as an operating system either the latest stable version of `Debian`
(no testing/unstable), or the latest stable version of `Rocky`.
`Debian` is highly recommended if you are new to system administration.

> ℹ️ Setting up Rocky is quite complex. Therefore, you don’t have to set up KDump.
> However, SELinux must be running at startup and its configuration has to be adapted for the project’s needs.
> AppArmor for Debian must be running at startup too.

You must create at least 2 encrypted partitions using LVM. Below is an example of the
expected partitioning:

> ℹ️ During the defense, you will be asked a few questions about the operating system you chose.
> For instance, you should know the differences between `aptitude` and `apt`, or what SELinux or AppArmor is.
> In short, understand what you use!

A SSH service will be running on port 4242 only.
For security reasons, it must not be possible to connect using SSH as root.

> ℹ️ The use of SSH will be tested during the defense by setting up a new account.
> You must therefore understand how it works.

You have to configure your operating system with the `UFW` (or `firewalld` for Rocky)
firewall and thus leave only port 4242 open.

> ℹ️ Your firewall must be active when you launch your virtual machine.
> For Rocky, you have to use firewalld instead of UFW.

The hostname of your virtual machine must be your login ending with 42 (e.g., wil42).
You will have to modify this hostname during your evaluation.

- You have to implement a strong password policy.
- You have to install and configure sudo following strict rules.
- In addition to the root user, a user with your login as username has to be present.
- This user has to belong to the `user42` and `sudo` groups.
