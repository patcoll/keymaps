# my qmk keymaps

I got tired of maintaining my own fork of the QMK firmware repository. So many
files that aren't mine -- it was very distracting.

Plus more and more I was building firmware for rare boards that did not have
their firmware committed to the main QMK repo. What to do?

The code in this repo contains my userspace and the custom keymaps I need to
get the most out of the boards I have. It also contains scripts to set the QMK
environment up that I need.

For local dev, it assumes you have `mise`, `uv`, `git`, and `rsync`, and
probably more. `mise` runs the tasks; `uv` installs the `qmk` CLI.

## preamble

It's worth noting that QMK recommends not using the latest AVR GCC (`avr-gcc`)
package. In its own setup scripts (referenced from `util/qmk_install.sh` at the
time of this writing), it explicitly installs an old version before attempting
to connect to a package repo to install the latest.

The install scripts are good reference points to help you install the right
versions locally.

## quick setup

First, install the QMK CLI by following the official guide at
<https://docs.qmk.fm/cli>. That installs the build prerequisites (compiler
toolchains) that `mise run setup` relies on.

Then run `uv sync`, `mise run setup`, and `mise run sync-all` to set everything
up. Running them again should do the bare minimum to get you to a working
environment. Check out `mise.toml` and the `mise-tasks/` folder if you are
curious what they do.

Once set up, run `qmk` commands through mise. For example:

    mise run qmk flash -kb keyhive/ut472 -km patcoll

## get more custom

If you need to use firmware from a repo that is not the main repo, drop its
files under `firmware/` and add the keyboard to the `keymaps` file. `mise run
sync <keyboard>` rsyncs those files into the main QMK repo under `working_area`.

I've found that most/all QMK forks with custom firmware can have their custom
firmware files copied into the latest version of the main QMK repo and compiled
without any issues. This way you always have the latest QMK bugfixes and
improvements and the custom firmware you need. Best of both worlds.

There are examples under `firmware/` to copy and customize.

## test all keymaps

When editing files in the userspace, it can be useful to test your changes
across all custom keymaps.

Run `mise run test` to test building all the keymaps.
