define(["require","exports","tslib","redux-saga","rondo-saga/v1/effects/take"],(function(e,r,t,n,s){"use strict";Object.defineProperty(r,"__esModule",{value:!0});var a=n.effects.race;function i(e,r){return t.__generator(this,(function(t){switch(t.label){case 0:return[4,a(e.map((function(e){return s.take(Array.isArray(e[r])?e[r]:[e[r]])})))];case 1:return[2,t.sent()]}}))}function c(e,r){for(var t=0;t<r.length;t++)if(void 0!==r[t])return{listener:e[t],action:r[t]}}r.listenersRace=i,r.listenersRaceResult=c,r.raceListeners=function(e,r){var n;return t.__generator(this,(function(t){switch(t.label){case 0:return[4,i(e,r)];case 1:return n=t.sent(),[2,c(e,n)]}}))}}));
//# sourceMappingURL=race.min.js-vfl2Kp9y8.map