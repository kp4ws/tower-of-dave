# Team Version Control Processes

### Overview
- Production ready branch: Master
- Testing branch: Staging
- Development branch: Dev
- Local changes are made in separate individual branches
- One way procedure to merge from local branch to dev branch to staging branch and finally to master branch
- We utilize Pull Requests so that no changes are ever directly pushed into a specific branch

### Step 1: Clone the project into local environment
- Go the main page of the Github repo, https://github.com/kp4ws/project-jump
- Press the green "Code" button to open a dropdown menu
- With HTTPS selected (by default) copy the provided URL for the repo
- In your local environment, decide which location you'd like to clone the repo
- When ready to clone, open a terminal window for the desired location and enter `git clone https://github.com/kp4ws/project-jump.git`
- If everything is correct, the repo should now be cloned into your local environment

### Step 2: Making local changes
- At this point you should be on the master branch of the repo, you need to create your own branch to make changes
- `git checkout -b branchname` to checkout and create branch in one command
- You are now in your own branch and can make changes

### Step 3: Pushing local changes to the server
- You've made changes and are ready to push them back to the server
- `git status` to verify the changes you've made. If there's additional changes here you didn't mean to make then revert those specific files
- `git add .` to stage all of your changes (there's variations of this command, such as git add --all)
- `git commit -m 'commit description'` to commit your changes. Make sure to leave a descriptive commit message here
- `git push origin branchname` to push your local branch changes into your branch on the Github server

### Step 4: Make a pull request
- After you've pushed changes to the Github server, make a pull request so that the master toucher knows there's changes to be merged
- Select branches in Github to view all branches
- Press new pull request to open up pull request menu.
- Select dev branch as the base branch and then press Create pull request
- At this point the pull request has been made and you are expected to notify the master touch via discord to let them know changes are ready to be merged

### Step 5: Updating master
- At this point, the remaining steps are performed by the master toucher
- Merge the pull request made by your team member into the dev branch.
- Make a pull request from dev branch into the staging branch.
- Once changes have been merged to staging, testing is performed at this point.
- If there's no breaking changes and everything appears to be correct, then create a pull request to master and merge changes into master
- At this point, the master branch should be updated

### Additional Steps - Pulling changes
- At any point when master branch has been updated, team members are notified in discord by the master toucher
- When the master branch is updated, team members are expected to pull changes first before pushing their changes
- In your local branch type, `git fetch origin` to retrieve the changes that were updated in the master branch
- `git checkout master` switch back to master branch so you can pull changes
- `git pull origin master ` pull changes from the master branch on the server into local master branch
- `git checkout branchname` switch back to your local branch
- `git merge master` merge changes into your local branch from master
- At this point your branch should be up to date with master once again.

### Additional Steps - Resolving conflicts with readable text files
- If basic conflicts, then resolve in Github conflict editor
- For more advanced conflicts, you'll need to resolve them in your local environment
- Open up visual studio code conflict editor and pick and choose which changes to keep and discard
- Afterward, either continue the merge in visual studio code or in your terminal window type `git merge --continue`
- Then add, commit, and push your changes back to Github server

### Additional Steps - Resolving conflicts with binary files (meta data files)
- Which ever files that have conflicts, make duplicate copies of those in your own branch
- After making the duplicate copies, then revert your local changes in the original files
- Then, the conflicts should be gone. Perform `git merge --continue`
- At this point, you'll need to manually pick and choose which stuff to keep and discard within Unreal Engine
- After doing so, you need to add, commit, and push your changes back to Github server

---

Here is an overview video showcasing some of the workflow described:  
https://www.youtube.com/watch?v=_XxPlggx9LU

--- 

![image](https://github.com/kp4ws/project-jump/assets/58745400/df1e218e-fb26-4d5c-b88e-5830db6b676e)
