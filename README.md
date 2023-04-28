# Ray Tracing in One Weekend

## Dev environment

- Use the Dockerfile to create an image. I call it `linux-cpp`.
- The `docker-compose` file uses this image and mounts the code as a volume.
- When using this, I need to `docker compose up`.
  - This starts up a Docker container.
  - VS Code has an "Attach to existing container" option that allows me to work within the container.
  - Alternatively, I can write my code in WSL. Docker Desktop has a way to create a terminal window. I can build and run from within there. Any changes will be reflected in the `build/` directory, since it is mounted to the container.
- VSCode has an extension called [PPM Viewer](https://marketplace.visualstudio.com/items?itemName=AYH.ppmviewer). Makes it very simple to view output PPM files.