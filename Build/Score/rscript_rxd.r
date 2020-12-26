a <- read.csv('/home/tk/Desktop/Model-of-Pancreatic-Islets/Build/Mods/data/watts_Alpha.csv')
b <- read.csv('/home/tk/Desktop/Model-of-Pancreatic-Islets/Build/Mods/data/watts_Beta.csv')
d <-read.csv('/home/tk/Desktop/Model-of-Pancreatic-Islets/Build/Mods/data/watts_Delta.csv')
View(a)
View(b)
View(d)
plot(a$Time, a$VC0)
plot(b$Time, b$VC0)
plot(d$Time, d$VC0)

# delta cell
d <-read.csv('/home/tk/Desktop/Model-of-Pancreatic-Islets/Build/Mods/data/watts_Delta.csv')
View(d)
plot(d$Time, d$VC0)
plot(d$D_Somatostatin_sstout)
plot(d$sst_ecs)
plot(d$D_Somatostatin_sstin)
plot(d$sst_cyt)
plot(d$D_Somatostatin_ist)

# somatostatin
plot(d$Time, d$D_Somatostatin_ist)
plot(d$Time, d$D_Somatostatin_sstin)
plot(d$Time, d$D_Somatostatin_sstout)
plot(d$Time, d$D_Somatostatin_Sst)
plot(a$Time, a$A_Glucagon_Sst)
plot(b$Time, b$B_Insulin_Sst)


