# Attach to the most recently created Docker container
docker attach $(docker container ls -lq)