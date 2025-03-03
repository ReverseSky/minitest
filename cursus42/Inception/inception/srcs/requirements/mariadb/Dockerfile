FROM debian:bullseye

RUN  apt update && apt install -y mariadb-server net-tools iputils-ping \
	 && apt clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod 777 /var/run/mysqld

COPY /tools/mariastart.sh /mariastart.sh

COPY conf/init.sql /docker-entrypoint-initdb.d/

RUN sed -i 's/bind-address\s*=.*/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

RUN chmod +x /mariastart.sh

EXPOSE 3306

ENTRYPOINT ["/mariastart.sh"]