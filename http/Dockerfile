FROM nginx
COPY nginx.conf /etc/nginx/nginx.conf
RUN mkdir -p /www
COPY ./sources /www
COPY ./nginx.conf /etc/nginx/conf.d
