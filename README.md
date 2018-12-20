# ft_ssl_md5 (42 School Project)

**ft_ssl_md5** is the first project in cryptographic branch of 42 School projects.

The goal is to create a program (written in C) that will combine functionality of **md5**, **openssl** and **shasum** Unix programs.

### Algorithms
The program handles encryption with several algorithms:
* md5
* SHA224
* SHA256
* SHA384
* SHA512
* SHA512224
* SHA512256

### How to run
* git clone https://github.com/itiievskyi/42-ft_ssl_md5.git ~/ft_ssl_md5
* cd ~/ft_ssl_md5/
* make
* ./ft_ssl command [command opts] [command args]

The program reads both files and standard input like **md5**. It also provides multifunctional input like **openssl** (launch without any arguments).
It has the same command options (except -x) and syntax as **md5**.

![SHA256](/images/1.png)

**ft_ssl** handles errors in the same way as system programs. It also supports multiple targets for every function (including binary files, strings and standard input).

![SHA256](/images/2.png)

### Enjoy!
